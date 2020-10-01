# An optimized version of Bubble Sort in Python3
# It works by stopping the algorithm if inner loop did not do any swap.
def bubble_Sort(arr): 
    n = len(arr) 
    for i in range(n): 
        swapped = False
  
        for j in range(0, n-i-1): 

            if arr[j] > arr[j+1] : 
                #Swapping the element
                arr[j], arr[j+1] = arr[j+1], arr[j] 
                swapped = True
        #Break if inner loop didn't do any swap 
        if swapped == False: 
            break
           

a = [63, 39, 58, 9, 22, 11, 90] 
bubble_Sort(a) 
print ("Sorted array is:") 
for i in range(len(a)): 
    print ("%d" %a[i],end=" ") 
  
