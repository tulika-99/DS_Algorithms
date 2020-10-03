#python3
import sys


def get_change(m):
    x = 0
    for _ in (10, 5, 1):
        change = m % _
        x += (m - change) // _
        m = change
    return x


if __name__ == '__main__':
    i = int(sys.stdin.read())
    if i <= 1000:
        print(get_change(i))
