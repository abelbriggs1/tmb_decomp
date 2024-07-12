"""
Implementation of the "clean" command.
"""

import argparse
import logging
import shutil

from build_system.env import Environment

LOG = logging.getLogger(__name__)


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "clean",
        help="Cleans the repository of build artifacts.",
        description="Cleans the repository of build artifacts.",
    )
    parser.set_defaults(func=_clean_cli)


def _clean_cli(env: Environment, args):
    """
    Handle the "clean" command of the CLI.
    """
    clean(env)
    LOG.info("Done cleaning build artifacts.")


def clean(env: Environment):
    """
    Clean the environment of any build artifacts, if they exist.
    This does not clean out splits.
    """
    if env.directories.build.is_dir():
        LOG.info("Cleaning build directory: %s", str(env.directories.build))
        shutil.rmtree(env.directories.build)
