"""
Breadth first search (BFS)

This algorithm traverses a graph breadth ward motion and
uses a queue to remember to get the next vertex to start
a search, when a dead end occurs in any iteration.
"""


"""
Below is a Graph
Nodes -> a, b, c, d, e, f
Edges -> (a,c), (b,c), (b,e), (c,d), (c,e)
"""
graph = { "a" : set(["c"]),
          "b" : set(["c","e"]),
          "c" : set(["a", "b", "d", "e"]),
          "d" : set(["c"]),
          "e" : set(["b","c"]),
          "f" : set([])
        }


"""
The BFS for above can go in following way

If the start Node is "b"
b  c  e  a  d
b  e  c  a  d
b  c  e  d  a
b  e  c  d  a
Notice that all three output are correct

If the start Node is "f"
Since no other node are connected
only "f" will be printed
"""

def bfs(graph, start):
    """
    Returns a list of nodes visited in
    breadth first manner from the start node
    """
    path = []
    # Track the visited and unvisited nodes using queue
    seen, queue = set([start]), [start]
    while queue:
        # Take the 1st element in the queue and explore it
        vertex = queue.pop(0)
        path.append(vertex)
        for node in graph[vertex]:
            if node not in seen:
                seen.add(node)
                queue.append(node)
    return path

for node in "abcdef":
    print("BFS for Node {} : {}".format(node,bfs(graph, node)))
