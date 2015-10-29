# Introduction #

The executables included in the Advanced Shell History program are coded to use a variable-visibility-level logging system.  This is similar to many popular logging systems such as [log4j](http://logging.apache.org/log4j/) or [google-glog](http://code.google.com/p/google-glog/).

In a nutshell, there are five levels of severity, each higher than the previous:
  * **DEBUG** -  The lowest level.  Used for troubleshooting and not for normal use.
  * **INFO** - Intended for significant events in the code that don't indicate a problem.
  * **WARNING** - Intended to indicate a potential problem, but not necessarily something wrong.
  * **ERROR** - This is an unexpected condition or problem.  Execution will continue, but this warrants user attention.
  * **FATAL** - The highest level.  Messages logged as fatal will be logged and then execution of the program will be halted.

Users can specify a visibility threshold in the settings - all levels of severity _below_ the threshold are suppressed.

# Details #

The program defines several configuration settings that allow you to customize where logged output is sent and which levels are to be visible.  See [this guide about configuration](HOWTO_Configure.md) for general configuration details.

The settings you want to be aware of are:
```
#
# Logging:
#

# ASH_CFG_LOG_FILE - Defines where logged messages are written.
ASH_CFG_LOG_FILE="${HOME}/.ash/ash.log"  # Default: ~/.ash/ash.log

# ASH_CFG_LOG_LEVEL - The minimum severity level that is logged to
#                     ASH_CFG_LOG_FILE.
#                     Severities (in increasing order):
#                       DEBUG, INFO, WARNING, ERROR, FATAL
ASH_CFG_LOG_LEVEL='DEBUG'  # Default: WARNING

# ASH_CFG_LOG_DATE_FMT - The timestamp format string used by the logger.
ASH_CFG_LOG_DATE_FMT='%Y-%m-%d %H:%M:%S %Z: '  # Default: %Y-%m-%d %H:%M:%S %Z:
```

## Tips ##

If you want to view debugging output on the console, you can set `ASH_CFG_LOG_FILE=/dev/stderr` in your shell environment.  When you are done, you can reset the variable to `ASH_CFG_LOG_FILE=~/.ash/ash.log`.

If you find a bug, _please_ turn on debugging to level DEBUG and include debug output to support your case when you [raise an issue.](http://code.google.com/p/advanced-shell-history/issues/entry)