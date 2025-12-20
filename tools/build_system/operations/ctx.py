"""
Implementation of the "ctx" command.
"""

import argparse
import logging
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
    parser.set_defaults(func=_ctx_cli)


def _ctx_cli(env: Environment, args):
    """
    Handle the "ctx" command of the CLI.
    """
    generate_ctx(env, args.c_file)


def _clean_up_context(output: str, stock_macros: str) -> str:
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


def generate_ctx(env: Environment, c_file: Path):
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
    result_text = _clean_up_context(result_text, stock_macros)

    Path("ctx.h").write_text(result_text, encoding="utf-8")
    LOG.info("Wrote final context to `ctx.h.")
