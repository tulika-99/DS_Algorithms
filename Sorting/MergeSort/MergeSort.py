def merge_sort(arr): 
    if len(arr)>1: #In order to reduce overflow
        m = len(arr)//2 #We find the medium of the array
        left = arr[:m]  #We slice the first half of the array
        right = arr[m:] #We slice the second half of the array
        left = merge_sort(left)  #Order the first half of the array
        right = merge_sort(right)  #Order the second half of the array
  
        arr =[] #We create the array that will have the answer
  
        while len(left)>0 and len(right)>0: #While we have elements on both of the subarrays we move comparing
            if left[0]<right[0]:  #If there's one on the left smaller than one of the right we append it to the answer and remove from the left 
                arr.append(left[0]) 
                left.pop(0) 
            else:  #If there's one o the left greater or equal than one on the right we just append him to the answer and remove the one from the right 
                arr.append(right[0]) 
                right.pop(0) 
        arr += left + right #Finally we just concat the ans with the values that still are on the left and the right, it have to be done because one array will get empty faster than other and it means that we need to join the part that still with elements.
        #Personally i recommend to understand it better to use the print function and check what's happening

    return arr 
