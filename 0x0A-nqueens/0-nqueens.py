#!/usr/bin/python3
"""
Module 0-nqueens
"""
from sys import argv


def nQueens(n):
    """
    : nQueens - finds all possible permutations where none of the N queens are
    :           vulnerable.
    : n: siz eof board n by n
    : Return: 2D array consisting of permutations
    """
    def has_no_diag(coord, placed):
        """
        : has_no_diag - checks if coord contains any queens in a diagonal path
        : coord: x, y board coordinate
        : placed: tracks placed coordinates in a given permutation challenge
        : Return: True if no impeding diagonal queens; False otherwise
        """
        i = coord[0]
        j = coord[1]
        while i >= 0 and j >= 0:
            i -= 1
            j -= 1
            if (i, j) in placed:
                return False

        i = coord[0]
        j = coord[1]
        while i >= 0 and j < n:
            i -= 1
            j += 1
            if (i, j) in placed:
                return False
        return True

    stk = [((0, i), {(0, i)}, {j for j in range(n) if j != i})
           for i in range(n)]
    perms = []
    retval = []
    while stk:
        curr, placed, cols = stk.pop(0)
        if len(placed) == n:
            if placed not in perms:
                perms.append(placed)
        x = curr[0]
        y = curr[1]
        if x == n-1:
            continue
        for j in range(n):
            if (j < n and (j > y + 1)) or (j >= 0 and (j < y - 1)):
                if j in cols and has_no_diag((x+1, j), placed):
                    new_tuple = ((x+1, j), placed.union({(x+1, j)}),
                                 cols - {j})
                    stk.append(new_tuple)

    for perm in perms:
        ret = [0 for _ in range(n)]
        for i, coord in enumerate(perm):
            ret[coord[0]] = list(coord)
        retval.append(ret)
    return retval


def main():
    """Program entry point"""
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    n = argv[1]
    if n.isdigit() is False:
        print("N must be a number")
        exit(1)
    n = int(n)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    print(nQueens(int(n)))

if __name__ == "__main__":
    main()
