"""
Implementation of the "split" command.
"""

import argparse
import logging

import splat.scripts.split as splat_split

from build_system.env import Environment
from .distclean import distclean

LOG = logging.getLogger(__name__)


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "split",
        help="Invokes `splat` to split and disassemble the target binary.",
        description="Invokes `splat` to split and disassemble the target binary.",
    )
    parser.add_argument(
        "--clean",
        "-c",
        help="Distclean the environment before splitting.",
        action="store_true",
    )
    parser.set_defaults(func=_split_cli)


def _split_cli(env: Environment, args):
    """
    Handle the "split" command of the CLI.
    """
    split(env, clean_first=args.clean)
    LOG.info("Done splitting binary.")


def split(env: Environment, clean_first: bool = False):
    """
    Split and disassemble the target binary.

    If `clean_first` is `True`, the environment will be cleaned of build artifacts
    and previous splits/disassembly before splitting.
    """

    if clean_first:
        LOG.info("Cleaning the repository before splitting binary.")
        distclean(env)

    LOG.info("Invoking `splat` to split the binary.")
    splat_split.main(
        config_path=[str(env.files.splat_yaml)], modes="all", verbose=False
    )
