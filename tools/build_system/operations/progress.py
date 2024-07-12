"""
Implementation of the "progress" command.
"""

import argparse
import logging

from pathlib import Path

import mapfile_parser
from mapfile_parser import ProgressStats

from build_system.env import Environment

LOG = logging.getLogger(__name__)


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "progress",
        help="Calculates decompilation progress.",
        description="Calculates decompilation progress.",
    )
    parser.add_argument(
        "--map-file",
        "-m",
        help="Linker map file to calculate progress for.",
        type=Path,
        required=False,
        default=None,
    )
    parser.add_argument(
        "--output",
        "-o",
        help="File to output the progress text to, if desired.",
        type=Path,
        required=False,
        default=None,
    )
    parser.set_defaults(func=_progress_cli)


def _progress_cli(env: Environment, args):
    """
    Handle the "progress" command of the CLI.
    """
    progress(env, args.map_file or env.files.ldmap)


def progress(env: Environment, ld_map_file: Path, output_path: Path = None):
    """
    Calculate progress of the decompilation.
    """
    map_file = mapfile_parser.MapFile()
    map_file.readMapFile(ld_map_file)

    total_stats, stats_per_folder = map_file.filterBySectionType(".text").getProgress(
        asmPath=env.directories.asm, nonmatchings=env.directories.nonmatchings
    )

    lines = [
        ProgressStats.getHeaderAsStr(),
        total_stats.getEntryAsStr("all", total_stats),
        "",
        *[
            stats.getEntryAsStr(folder, total_stats)
            for folder, stats in stats_per_folder.items()
        ],
    ]

    for line in lines:
        print(line)

    if output_path is not None:
        output_path.write_text("\n".join(lines), encoding="UTF-8")
