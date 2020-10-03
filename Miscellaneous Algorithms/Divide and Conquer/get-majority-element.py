#python3
import sys

def get_majority_element(a, n):
    m = {}

    for i in range(n):
        if a[i] in m:
            m[a[i]] += 1
        else:
            m[a[i]] = 1

    count = 0

    for key in m:
        if m[key] > n / 2:
            return 1

    if (count == 0):
        return -1


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))

    if get_majority_element(a, n) != -1:
        print(1)
    else:
        print(0)
