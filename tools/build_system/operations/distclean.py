"""
Implementation of "distclean" command.
"""

import argparse
import logging
import shutil

from build_system.env import Environment
from .clean import clean

LOG = logging.getLogger(__name__)


def add_subparser(subparsers):
    """
    Add the argument parser for the command to the action object for
    the main parser.
    """
    parser: argparse.ArgumentParser = subparsers.add_parser(
        "distclean",
        help="Completely clean the repository of build artifacts and disassembly.",
        description="Completely clean the repository of build artifacts and disassembly.",
    )
    parser.set_defaults(func=_distclean_cli)


def _distclean_cli(env: Environment, args):
    """
    Handle the "distclean" command of the CLI.
    """
    distclean(env)
    LOG.info("Done cleaning build artifacts and disassembly/splits.")


def distclean(env: Environment):
    """
    Completely clean the repository of build artifacts and disassembly.
    """
    clean(env)

    if env.directories.assets.is_dir():
        LOG.info("Cleaning assets directory: %s", str(env.directories.assets))
        shutil.rmtree(env.directories.assets)

    if env.directories.asm.is_dir():
        LOG.info("Cleaning ASM directory: %s", str(env.directories.asm))
        shutil.rmtree(env.directories.asm)

    if env.files.ldscript.is_file():
        LOG.info("Removing generated linker script: %s", str(env.files.ldscript))
        env.files.ldscript.unlink()

    if env.files.splat_cache.is_file():
        LOG.info("Removing `splat` cache: %s", str(env.files.splat_cache))
        env.files.splat_cache.unlink()

    if env.files.build_script.is_file():
        LOG.info(
            "Removing generated Ninja build script: %s", str(env.files.build_script)
        )
        env.files.build_script.unlink()
