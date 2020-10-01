 #Merge Sort Function
 def mergeSort(a): 
    if len(a) >1: 
        mid = len(a)//2       # Finding the mid of the array 
        L = a[:mid]           # Dividing the array elements  
        R = a[mid:]           # into 2 halves 
  
        mergeSort(L)          # Sorting the first half 
        mergeSort(R)          # Sorting the second half 
  
        i = j = k = 0
          
        # Copy data to temp arrays L[] and R[] 
        while i < len(L) and j < len(R): 
            if L[i] < R[j]: 
                a[k] = L[i] 
                i+= 1
            else: 
                a[k] = R[j] 
                j+= 1
            k+= 1
          
        # Checking if any element was left 
        while i < len(L): 
            a[k] = L[i] 
            i+= 1
            k+= 1
          
        while j < len(R): 
            a[k] = R[j] 
            j+= 1
            k+= 1
  
  
# driver code to test the above code 
if __name__ == '__main__': 
    a=list(map(int,input('Enter the array').split()))
    print ("Given array is: ")  
    print(a) 
    mergeSort(a) 
    print("Sorted array is: ") 
    print(a) 
  
