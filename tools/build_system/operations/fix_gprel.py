"""
Implementation of the "fix_gprel" command.
"""

import argparse
import logging
import re

from build_system.env import Environment
from build_system.symbols import parse_symbol_addrs

LOG = logging.getLogger(__name__)

GPREL_REGEX = re.compile(r"^(.*)%gp_rel\(([^)]+)\)(.*)$")


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "fix_gprel",
        help="Modifies 'nonmatching' ASM included in C files to replace `gp_rel` relocations.",
        description="Modifies 'nonmatchings' ASM included in C files to replace `gp_rel` relocations.",
    )
    parser.set_defaults(func=_fix_gprel_cli)


def _fix_gprel_cli(env: Environment, args):
    """
    Handle the "fix_gprel" command of the CLI.
    """
    fix_gprel(env)
    LOG.info("Done fixing 'gprel' relocations.")


def fix_gprel(env: Environment):
    """
    Modifies 'nonmatchings' ASM included in C files to replace `gp_rel` relocations.

    This command exists because the old GAS version used by PS2 compilers does not
    support `%gp_rel` relocations, and therefore does not compile when included into
    a C translation unit.

    When assembling raw .s files which aren't included in C files, we don't need to
    worry about this because we call into a modern GAS directly. However, we have to
    use the old assembler for matching C/C++ TUs.
    """

    symbol_addrs: dict[str, int] = parse_symbol_addrs(env.files.splat_symbols)

    for asm_file in sorted(env.directories.nonmatchings.glob("**/*.s")):
        LOG.info("Replacing gp-relative relocations in %s", str(asm_file))

        new_lines: list[str] = []
        with asm_file.open("r") as f:
            for line in f:
                match = GPREL_REGEX.match(line)
                address: int = None

                if match is not None:
                    instr_pre: str = match.group(1)
                    instr_post: str = match.group(3)
                    symbol: str = match.group(2)

                    if symbol.startswith("D_"):
                        symbol = symbol.replace("D_", "0x")
                        address = int(symbol.replace("D_", "0x"), 0)
                    else:
                        address = symbol_addrs[symbol]

                    gp_rel: int = address - env.toolchain.gp_value
                    new_line = f"{instr_pre}{hex(gp_rel)}{instr_post}\n"
                else:
                    new_line = line

                new_lines.append(new_line)

        with asm_file.open("w") as f:
            f.writelines(new_lines)
