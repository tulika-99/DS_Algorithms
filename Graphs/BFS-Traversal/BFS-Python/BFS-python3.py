#Importing default dictionary of python to store the Graph
#Implemented the Adjacency List Represtation of the Graph
from collections import defaultdict 

'''
    Class representating the Graph Data Structure and the methods assosciated.
    In the Constructor i.e., initialization of Graph default dictionary of python is used.
    Considering Undirected Graph, add 2 edges from source to destination and vice versa.
    For running BFS from all nodes, get the number of nodes in Graph
    Lastly,BFS traversal is done from a starting node.
    BFS Algorithm is fairly simple (Similar to Level Order Traversal of a Tree):
        1. Start Traversing from the start node, add this node to the queue and mark it as Visited
        2. Run a loop till queue is empty
            2.a. Pop the element from the queue and print it
            2.b. Check for adjacent nodes of this node and append it to the queue & mark visited 
'''
class Graph: 
  
    def __init__(self): 
        self.graph = defaultdict(list) 
  
    def addEdge(self,u,v): 
        self.graph[u].append(v) 
        self.graph[v].append(u) 
        
    def size(self):
        return len(self.graph)
  
    def BFS(self, s): 
  
        #Visited array of nodes to check if it is already visited
        visited = [False] * (len(self.graph)) 
  
        # Create a queue for BFS 
        queue = [] 
   
        queue.append(s) 
        visited[s] = True
  
        while queue: 
  
            s = queue.pop(0) 
            print (s, end = " ") 
  
            for i in self.graph[s]: 
                if visited[i] == False: 
                    queue.append(i) 
                    visited[i] = True
  
  
#Creating the graph

g = Graph() 
g.addEdge(0, 1) 
g.addEdge(0, 2) 
g.addEdge(1, 3) 
g.addEdge(1, 4) 
g.addEdge(2, 4) 
g.addEdge(3, 4) 
g.addEdge(3, 5) 
g.addEdge(4, 5) 

n = g.size()
print("The Breadth First traversal from all the nodes is: ")
for i in range(n):
    print('As starting node ' + str(i))
    g.BFS(i)
    print('\n-----------')