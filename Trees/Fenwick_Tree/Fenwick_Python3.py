#Python - Binary Indexed Tree 
  
#Returns sum of arr[0..index]
def getsum(BITTree,i): 
    s = 0
    i = i+1
    while i > 0:
        s += BITTree[i] 
        i -= i & (-i) 
    return s 
  
#Updates a node in BITree at given index 
def updatebit(BITTree , n , i ,v): 
    i += 1
    while i <= n: 
        BITTree[i] += v 
        i += i & (-i) 
  
#Rreturns a BITree for given array
def construct(arr, n): 
    BITTree = [0]*(n+1) 
    for i in range(n): 
        updatebit(BITTree, n, i, arr[i]) 
    return BITTree 
