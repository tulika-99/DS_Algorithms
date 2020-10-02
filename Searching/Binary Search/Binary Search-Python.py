#Binary Search function returns the position of number in array or -1 if not found
def binarySearch(arr, num):
  left = 0
  right = len(arr)- 1
  mid = 0
  while(left < right):
      mid = (left + right)//2
      if(arr[mid] == num):
          return mid
      if(arr[mid] < num):
          left = mid + 1
      else:
          right = mid - 1
  if(arr[left] == num):
      return left
  return -1
print(binarySearch([2,56,6,1,12,2,666],666))

