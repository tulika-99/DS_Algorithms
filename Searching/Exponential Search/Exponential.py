#exponential Search function returns the position of number in array or -1 if not found


def binarySearch(A, left, right, x):
 
    if left > right:
        return -1
 
    mid = (left + right) // 2
 
    if x == A[mid]:
        return mid+1
 
    elif x < A[mid]:
        return binarySearch(A, left, mid - 1, x)
    else:
        return binarySearch(A, mid + 1, right, x)
 
 
# Returns the position of key `x` in a given list `A` of length `n`
def exponentialSearch(A, x):
 
    index = 1
    while index < len(A) and A[index] < x:
        index *= 2     
    return binarySearch(A, index // 2, min(index, len(A)), x)
 
print(exponentialSearch([2, 5, 6, 8, 9, 10],10))