#!/usr/bin/python3
""" 0-stats - tracks response codes and total file size """
from collections import defaultdict
import signal
import sys


def signal_handler(signal, frame):
    """ outputs stats and exits app """
    output()
    sys.exit(0)


def output():
    """ outputs current state of code count and total file size """
    print("File size: {}".format(size))
    for code in codes:
        if _dict.get(code):
            print("{}: {}".format(code, _dict[code]))

size = 0
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
_dict = defaultdict(int)

signal.signal(signal.SIGINT, signal_handler)
i = 1
for line in sys.stdin:
    line = line.split()
    status = line[7]
    size += int(line[8])
    _dict[status] += 1
    if i % 10 == 0 and i > 0:
        output()
    i += 1
