#!/usr/bin/env python3
import sys
from pathlib import Path

_ROOT = Path(__file__).parent
# Place our "build system" Python code in the PYTHONPATH so we can import it.
sys.path.append(str(_ROOT / "tools"))

from build_system.cli import cli  # noqa

if __name__ == "__main__":
    cli(_ROOT)
