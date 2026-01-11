"""
Implementation of the "permute" command.
"""

import argparse
import logging
import stat
import subprocess
from pathlib import Path
from typing import Optional

from build_system.env import Environment

from .ctx import generate_ctx

LOG = logging.getLogger(__name__)


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "permute",
        help="Sets up `decomp-permuter` for a specific function.",
        description="Sets up `decomp-permuter` for a specific function.",
    )
    parser.add_argument(
        "src_file",
        help="The source file which contains the function to permute.",
        type=Path,
    )
    parser.add_argument(
        "func_name",
        help="The (unmangled) function name to permute in the source file.",
        type=str,
    )
    parser.set_defaults(func=_permute_cli)


def _permute_cli(env: Environment, args):
    """
    Handle the "permute" command of the CLI.
    """
    permute(env, args.src_file, args.func_name)


def _search_for_func_asm(dir: Path, func_name: str) -> Optional[Path]:
    """
    Search for an `.s` file in the given `dir` which may contain the assembly
    of the given function. Looks for an exact match - if not found, will attempt
    to fuzzy-match for mangled functions.
    """

    # Look for exact matches, for unmangled function names.
    pattern = f"{func_name}.s"
    results = sorted(dir.glob(pattern))
    if results:
        # Found an exact match.
        return results[0]

    # Assume the function name is mangled with GNU2 mangling.
    pattern = f"{func_name}__*.s"
    results = sorted(dir.glob(pattern))
    if results:
        # Return the first match alphabetically if there were multiple.
        # TODO: This won't handle overloads correctly.
        return results[0]

    return None


def permute(env: Environment, src_file: Path, func_name: str):
    """
    Set up `decomp-permuter` for a specific function.
    """
    if src_file.suffix == ".cpp":
        raise NotImplementedError("`decomp-permuter` does not support C++.")
    # TODO: Properly handle name mangling and overloads.

    perm_dir = Path("nonmatchings")
    perm_dir.mkdir(exist_ok=True)
    perm_dir = perm_dir / func_name

    try:
        tu_path: Path = (
            src_file.absolute().relative_to(env.directories.src).with_suffix("")
        )
    except Exception as e:
        raise FileNotFoundError("Source file must be in the `src/` directory.") from e

    func_asm = _search_for_func_asm(env.directories.nonmatchings / tu_path, func_name)
    if func_asm is None:
        func_asm = _search_for_func_asm(env.directories.matchings / tu_path, func_name)
        if func_asm is None:
            raise FileNotFoundError(
                f"Unable to find `.s` file for function `{func_name}`."
            )

    # Create the permuter directory.
    perm_dir.mkdir(exist_ok=True)

    # Create the `compile.sh` file.
    compile_script = perm_dir / "compile.sh"
    with compile_script.open("w", encoding="utf-8") as f:
        if src_file.suffix == ".cpp":
            cmd = env.generate_cxx_compiler_cmd()
        else:
            cmd = env.generate_c_compiler_cmd()

        f.write(f'#!bin/bash\n{cmd} "$@"')
    compile_script.chmod(compile_script.stat().st_mode | stat.S_IEXEC)

    # Add the source file after context processing.
    generate_ctx(
        env,
        src_file,
        keep_funcs=[func_name],
        # result_file=(perm_dir / "base").with_suffix(src_file.suffix)
        result_file=(perm_dir / "base.c"),
    )

    # Assemble the original ASM to get a target object for comparison.
    # We need to add a few things to make it assemble.
    tmp_asm: Path = perm_dir / "target.s"
    with tmp_asm.open(mode="w", encoding="utf-8") as f:
        f.writelines(
            [
                '.include "macro.inc"\n',
                ".set noat\n",
                ".set noreorder\n\n",
            ]
        )
        f.write(func_asm.read_text(encoding="utf-8"))
    subprocess.check_output(
        f"{env.generate_assembler_cmd()} {tmp_asm} -o {perm_dir / 'target.o'}",
        shell=True,
    )

    LOG.info("Permuter directory created at `%s`.", str(perm_dir))
