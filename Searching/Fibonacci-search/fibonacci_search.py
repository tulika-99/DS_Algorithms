from bisect import bisect_left

def fibonacciSearch(arr, x, n):
  
    # Initialize fibonacci numbers
    fibonacciNum2 = 0  # (m-2)'th Fibonacci No.
    fibonacciNum1 = 1  # (m-1)'th Fibonacci No.
    fibonacciNumM = fibonacciNum2 + fibonacciNum1  # m'th Fibonacci
  
    # fibonacciNumM is going to store the smallest
    # Fibonacci Number greater than or equal to n
    while (fibonacciNumM < n):
        fibonacciNum2 = fibonacciNum1
        fibonacciNum1 = fibonacciNumM
        fibonacciNumM = fibonacciNum2 + fibonacciNum1
  
    # Marks the eliminated range from front
    offset = -1
  
    # while there are elements to be inspected.
    # Note that we compare arr[fibonacciNumMm2] with x.
    # When fibonacciNumM becomes 1, fibonacciNumMm2 becomes 0
    while (fibonacciNumM > 1):
  
        # Check if fibonacciNumMm2 is a valid location
        i = min(offset+fibonacciNum2, n-1)
  
        # If x is greater than the value at
        # index fibonacciNum2, cut the subarray array
        # from offset to i
        if (arr[i] < x):
            fibonacciNumM = fibonacciNum1
            fibonacciNum1 = fibonacciNum2
            fibonacciNum2 = fibonacciNumM - fibonacciNum1
            offset = i
  
        # If x is less than the value at
        # index fibonacciNumMm2, cut the subarray
        # after i+1
        elif (arr[i] > x):
            fibonacciNumM = fibonacciNum2
            fibonacciNum1 = fibonacciNum1 - fibonacciNum2
            fibonacciNum2 = fibonacciNumM - fibonacciNum1
  
        # element found. return index
        else:
            return i
  
    # comparing the last element with x */
    if(fibonacciNum1 and arr[n-1] == x):
        return n-1
  
    # element not found. return -1
    return -1
  
  
# Driver Code
array = [2, 5, 7, 3, 1, 9, 10, 15, 16]
n = len(array)
toFind = 9
index = fibonacciSearch(array, toFind, n)
if index >= 0:
  print("Found at:", index)
else:
  print(x," not found in the array");
  
