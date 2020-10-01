"""
Depth first search (DFS)

This algorithm traverses a graph in a depth ward motion
and uses a stack to remember to get the next vertex to
start a search, when a dead end occurs in any iteration.
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
The DFS for above can go in following way

If the start Node is "a"
a  c  b  e  d
a  c  d  b  e
a  c  e  b  d
Notice that all three output are correct

If the start Node is "f"
Since no other node are connected
only "f" will be printed
"""

def dfs(graph, start, visited = None, path = None):
    """
    Returns a list of nodes visited in
    depth first manner from the start node
    """
    if visited is None:
        visited = set()
    if path is None:
        path = []
    visited.add(start)
    path.append(start)
    for next in graph[start] - visited:
        dfs(graph, next, visited, path)
    return path

for node in "abcdef":
    print("DFS for Node {} : {}".format(node,dfs(graph, node)))
