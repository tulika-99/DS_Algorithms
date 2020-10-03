def linearsearch(arr,x):
    for i in range(len(arr)):
        if arr[i] == x:
            print("{} found at position {}".format(x,i))
            return
    print("{} not in the given array.".format(x))
arr = [1,2,3,4,5,7,8,9,10]
# success-case
linearsearch(arr,1)
# failure-case
linearsearch(arr,6)
