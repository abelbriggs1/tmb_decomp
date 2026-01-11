"""
Implementation of the "ctx" command.

The code for stripping function definitions was originally developed by
Simon Lindholm for `decomp-permuter`, licensed under MIT.
"""

import argparse
import logging
import re
import subprocess
import tempfile
from pathlib import Path

from build_system.env import Environment

LOG = logging.getLogger(__name__)


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "ctx",
        help="Generates a context file for use with decomp.me.",
        description="Generates a context file for use with decomp.me.",
    )
    parser.add_argument(
        "c_file",
        help="Source file to generate context for.",
        type=Path,
    )
    parser.add_argument(
        "--keep-funcs",
        help=(
            "A (unmangled) function name whose implementation (if one exist) should be left in the output. "
            "All other function implementations will be stripped from the output."
            "Multiple functions can be listed after the flag."
        ),
        nargs="*",
        required=False,
    )
    parser.add_argument(
        "--output",
        help="Path to output the resulting context file. Defaults to `ctx.h`.",
        type=Path,
        default=Path("ctx.h"),
    )
    parser.set_defaults(func=_ctx_cli)


def _ctx_cli(env: Environment, args):
    """
    Handle the "ctx" command of the CLI.
    """
    generate_ctx(env, args.c_file, args.keep_funcs, args.output)


def _clean_up_macros(output: str, stock_macros: str) -> str:
    """
    Clean up the output of the C preprocessor by removing macros pre-defined
    by the compiler.
    """

    def parse_define_name(line: str) -> str:
        return line.split()[1].split("(")[0]

    defines = {}
    source_lines = []
    for line in output.splitlines(keepends=True):
        if line.startswith("#define"):
            sym = parse_define_name(line)
            defines[sym] = line
        elif line.startswith("#undef"):
            sym = parse_define_name(line)
            if sym in defines:
                del defines[sym]
        else:
            if line.strip().startswith("__asm__ volatile"):
                continue
            source_lines.append(line)

    for line in stock_macros.strip().splitlines():
        sym = parse_define_name(line)
        if sym in defines:
            del defines[sym]

    return "".join(defines.values()) + "".join(source_lines)


def _find_bracket_end(output: str, start: int) -> int:
    """
    Given an opening bracket `{` in a C-like source file, find the index
    of the corresponding closing bracket `}`.
    """

    level = 1
    assert output[start] == "{"
    i = start + 1
    while i < len(output):
        if output[i] == "{":
            level += 1
        elif output[i] == "}":
            level -= 1
            if level == 0:
                break

        i += 1

    assert level == 0, "unbalanced brackets {}"
    return i


def _strip_function_defs(output: str, keep_funcs: list[str]):
    """
    Strip function definitions from the context.
    """
    result = ""
    remain = output
    func_re = re.compile(r"^[^#\n]*\s+\**(\w+)\(.*\)\s*?{", re.M)

    if keep_funcs is None:
        keep_funcs = []

    while True:
        fn = re.search(func_re, remain)
        if fn is None:
            result += remain
            remain = ""
            break

        name = fn.group(1)
        bracket_end = _find_bracket_end(remain, fn.end() - 1)
        if name in keep_funcs:
            result += "\n\n" + remain[: bracket_end + 1] + "\n\n"
        else:
            result += remain[: fn.end() - 1].rstrip() + ";"

        remain = remain[bracket_end + 1 :]

    return result


def generate_ctx(
    env: Environment, c_file: Path, keep_funcs: list[str], result_file: Path
):
    """
    Generate a context file for use with decomp.me.
    """
    if not c_file.is_file():
        raise FileNotFoundError(f"Missing source file: `{c_file}`")

    LOG.info("Checking stock macros...")
    with tempfile.NamedTemporaryFile(suffix=".h", delete=True) as tmp:
        stock_macros = subprocess.check_output(
            f"{env.toolchain.c_preprocessor_cmd} -E -P -dM {tmp.name}",
            shell=True,
            encoding="utf-8",
        )

    LOG.info("Running C preprocessor on `%s`...", str(c_file))
    command = f"{env.generate_c_preprocessor_cmd(m2ctx=True)} {c_file}"
    result_text = subprocess.check_output(command, encoding="utf-8", shell=True)

    LOG.info("Prettifying output...")
    result_text = _clean_up_macros(result_text, stock_macros)
    result_text = _strip_function_defs(result_text, keep_funcs)

    result_file.write_text(result_text, encoding="utf-8")
    LOG.info("Wrote final context to `%s`.", str(result_file))
