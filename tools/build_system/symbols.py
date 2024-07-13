"""
Utilities to read `splat` symbols as a dictionary, where each symbol name maps to its
address.

This is an extremely minimal symbol file parser copied from Splat's code. Ideally, Splat
should be updated to let us use its infrastructure/parser freely - however, the parser
is extremely coupled to Splat's global state as of writing.
"""

import logging
from pathlib import Path

LOG = logging.getLogger(__name__)


def parse_symbol_addrs(symbols_file: Path) -> dict[str, int]:
    """
    Get the `splat` symbols as a dictionary, where each symbol name maps to its
    properties.
    """

    symbols: dict[str, int] = {}
    with symbols_file.open("r", encoding="UTF-8") as f:
        for line in f:
            line = line.strip()

            if not line or line.startswith("//"):
                continue

            comment_loc = line.find("//")
            line_main = line

            if comment_loc != -1:
                line_main = line[:comment_loc].strip()

            try:
                assert line.count(";") == 1, "Line must contain a single semi-colon"
                line_split = line_main.split("=")
                name = line_split[0].strip()
                addr = int(line_split[1].strip()[:-1], 0)
            except:
                LOG.error("Line must be of the form")
                LOG.error("<function_name> = <address>; // attr0:val0 attr1:val1 [...]")
                LOG.error("with <address> in hex preceded by 0x, or dec")
                LOG.error("")
                raise

            symbols[name] = addr

    return symbols
