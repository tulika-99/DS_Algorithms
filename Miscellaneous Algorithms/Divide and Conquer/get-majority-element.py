#python3
import sys

#defining the function
def get_majority_element(a, n):
    m = {}

#collecting the elements
    for i in range(n):
        if a[i] in m:
            m[a[i]] += 1
        else:
            m[a[i]] = 1

    count = 0

#checking for the majority element
    for key in m:
        if m[key] > n / 2:
            return 1

#returning -1 if there is no majority element
    if (count == 0):
        return -1

#defining the input function
#taking input from the user in correct format
#refer readme
if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))

    if get_majority_element(a, n) != -1:
        print(1)
    else:
        print(0)
