# Python3 program to implement Union-Find  
# with union by rank and path compression. 
  
# set parent of every node to itself  
# and size of node to one  
def initialize(n): 
    global Arr, size 
    for i in range(n + 1): 
        Arr[i] = i  
        size[i] = 1
  
# Each time we follow a path, find  
# function compresses it further  
# until the path length is greater  
# than or equal to 1.  
def find(i): 
    global Arr, size 
      
    # while we reach a node whose  
    # parent is equal to itself  
    while (Arr[i] != i): 
        Arr[i] = Arr[Arr[i]] # Skip one level  
        i = Arr[i] # Move to the new level 
    return i 
  
# A function that does union of two  
# nodes x and y where xr is root node  
# of x and yr is root node of y  
def _union(xr, yr): 
    global Arr, size 
    if (size[xr] < size[yr]): # Make yr parent of xr  
        Arr[xr] = Arr[yr]  
        size[yr] += size[xr] 
    else: # Make xr parent of yr 
        Arr[yr] = Arr[xr]  
        size[xr] += size[yr] 
  
# The main function to check whether  
# a given graph contains cycle or not  
def isCycle(adj, V): 
    global Arr, size 
      
    # Itexrte through all edges of gxrph,  
    # find nodes connecting them.  
    # If root nodes of both are same,  
    # then there is cycle in gxrph. 
    for i in range(V): 
        for j in range(len(adj[i])): 
            x = find(i) # find root of i  
            y = find(adj[i][j]) # find root of adj[i][j]  
  
            if (x == y): 
                return 1 # If same parent  
            _union(x, y) # Make them connect 
    return 0
  
# Driver Code 
MAX_VERTEX = 101
  
# Arr to represent parent of index i  
Arr = [None] * MAX_VERTEX  
  
# Size to represent the number of nodes  
# in subgxrph rooted at index i  
size = [None] * MAX_VERTEX  
  
V = 3
  
# Initialize the values for arxry  
# Arr and Size  
initialize(V)  
  
# Let us create following gxrph  
#     0  
# | \  
# | \  
# 1-----2  
  
# Adjacency list for graph  
adj = [[] for i in range(V)]  
  
adj[0].append(1)  
adj[0].append(2)  
adj[1].append(2)  
  
# call is_cycle to check if it  
# contains cycle  
if (isCycle(adj, V)):  
    print("Graph contains Cycle.")  
else: 
    print("Graph does not contain Cycle.") 


#output:"Graph contains Cycle"
# Time Complexity(Find) : O(log*(n))
# Time Complexity(union) : O(1)