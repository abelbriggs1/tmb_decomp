#!/bin/bash
set -e

python3 -m virtualenv .venv
source .venv/bin/activate
pip install -r tools/requirements-python.txt
pre-commit install
activate-global-python-argcomplete
