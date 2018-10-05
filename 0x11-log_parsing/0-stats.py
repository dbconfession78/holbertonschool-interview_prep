#!/usr/bin/python3
""" 0-stats - tracks response codes and total file size """
from collections import defaultdict
import signal
import sys


class LogParser:
    """ parses total file size and status code count from input """
    def __init__(self):
        """ initializes LogParser """
        self.size = 0
        self.codes = ['200', '301', '400', '401', '403', '404', '405', '500']
        self.log = defaultdict(int)

    def run(self):
        """ executes the parser """
        signal.signal(signal.SIGINT, self.signal_handler)
        i = 1
        for line in sys.stdin:
            line = line.split()
            if line_format_is_ok(line):
                status = line[7]
                self.size += int(line[8])
                self.log[status] += 1
                if i % 10 == 0 and i > 0:
                    self.print_stats()
                i += 1

    def print_stats(self):
        """ outputs current state of code count and total file size """
        print("File size: {}".format(self.size))
        for key, value in sorted(self.log.items()):
            print("{}: {}".format(key, value))

    def signal_handler(self, signal, frame):
        """ outputs stats and exits app """
        self.print_stats()
        sys.exit(0)


def line_format_is_ok(line):
    """ checks if input line is in the correct format """
    if len(line) == 9:
        expected_method_path_prot = '"GET /projects/260 HTTP/1.1"'
        codes = {'200', '301', '400', '401', '403', '404', '405', '500'}
        ip = line[0]
        dash = line[1]
        date = line[2]
        time = line[3]
        method = line[4]
        path = line[5]
        protocol = line[6]
        code = line[7]
        size = line[8]
        if not ip_format_is_ok(ip):
            return False
            #        print('    - ip format: OK')

        if not dash == '-':
            return False
            #        print('    - dash format: OK')

        if not date_format_is_ok(date):
            return False
            #        print('    - date format: OK')

        if not time_format_is_ok(time):
            return False
            #        print('    - time format: OK')

        if expected_method_path_prot != ' '.join([method, path, protocol]):
            return False
            #        print('    - method format: OK')

        if code not in codes:
            return False

        if not size.isnumeric():
            return False

    return True


def date_format_is_ok(date):
    """ checks the date and time format """
    if not date.startswith('['):
        return False

    date = date[1:]
    if date.count('-') != 2:
        return False

    date = date.split('-')
    if len(date) != 3:
        return False

    if not all(x.isnumeric() for x in date):
        return False

    if len(date[0]) != 4 or len(date[1]) != 2 or len(date[2]) != 2:
        return False

    return True


def time_format_is_ok(time):
    """ checks time format """
    if time.count(':') != 2:
        return False

    time = time.split(':')
    if len(time) != 3:
        return False
    if not time[0].isnumeric() or not time[1].isnumeric():
        return False
    h = int(time[0])
    m = int(time[1])
    s = time[2]

    if h > 23 or m > 59:
        return False
    if len(s) != 10 or s[2] != '.':
        return False

    if s[-1] != ']' or not s[:2].isnumeric() or not s[3:-1].isnumeric():
        return False
    s = s.split('.')
    s = int(s[0])
    if s > 59:
        return False

    return True


def ip_format_is_ok(ip):
    """ checks format of ip address """
    if ip.count('.') != 3:
        return False

    ip = ip.split('.')
    if not all(x.isnumeric() for x in ip):
        return False

    return True


def main():
    """ entry point to module """
    LogParser().run()


if __name__ == '__main__':
    main()
