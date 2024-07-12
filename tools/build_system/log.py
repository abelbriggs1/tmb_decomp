import logging
import logging.config

import colorama


class ColorFormatter(logging.Formatter):
    """
    Log formatter which applies color to the "log level" text.
    """

    COLOR_MAP = {
        logging.DEBUG: colorama.Fore.CYAN,
        logging.INFO: colorama.Fore.GREEN,
        logging.WARN: colorama.Fore.YELLOW,
        logging.ERROR: colorama.Fore.RED,
        logging.CRITICAL: colorama.Fore.MAGENTA,
    }

    def format(self, record: logging.LogRecord) -> str:
        record.levelname = (
            f"{self.COLOR_MAP[record.levelno]}{record.levelname}{colorama.Fore.RESET}"
        )
        return super().format(record)


def get_logger_config(log_level: str) -> dict:
    return {
        "version": 1,
        "disable_existing_loggers": False,
        "formatters": {
            "console": {
                "class": "build_system.log.ColorFormatter",
                "format": "%(levelname)-18s : %(message)s",
            }
        },
        "handlers": {
            "console": {
                "class": "logging.StreamHandler",
                "formatter": "console",
                "stream": "ext://sys.stdout",
            }
        },
        "root": {"level": log_level, "handlers": ["console"]},
    }
