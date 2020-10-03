"""
Theory:
The topological sort algorithm takes a directed acyclic graph and returns an
array of the nodes where each node appears before all the nodes it points to.
A graph can have more than one valid topological ordering. Cyclic graphs don't
have valid topological orderings.

Algorithm:
1) Identify a node with no incoming edges.
2) Add that node to the ordering.
3) Remove it from the graph.
4) Repeat.
"""


# Time Complexity : O(N+E)
# Space Complexity : O(N)
def topological_sort(digraph):
    # digraph is a dictionary:
    #   key: a node
    # value: a set of adjacent neighboring nodes

    # construct a dictionary mapping nodes to their
    # indegrees
    indegrees = {node : 0 for node in digraph}
    for node in digraph:
        for neighbor in digraph[node]:
            indegrees[neighbor] += 1

    # track nodes with no incoming edges
    nodes_with_no_incoming_edges = []
    for node in digraph:
        if indegrees[node] == 0:
            nodes_with_no_incoming_edges.append(node)

    # initially, no nodes in our ordering
    topological_ordering = []

    # as long as there are nodes with no incoming edges
    # that can be added to the ordering
    while len(nodes_with_no_incoming_edges) > 0:

        # add one of those nodes to the ordering
        node = nodes_with_no_incoming_edges.pop()
        topological_ordering.append(node)

        # decrement the indegree of that node's neighbors
        for neighbor in digraph[node]:
            indegrees[neighbor] -= 1
            if indegrees[neighbor] == 0:
                nodes_with_no_incoming_edges.append(neighbor)

    # we've run out of nodes with no incoming edges
    # did we add all the nodes or find a cycle?
    if len(topological_ordering) == len(digraph):
        return topological_ordering  # got them all
    else:
        raise Exception("Graph has a cycle! No topological ordering exists.")


# Driver Code
if __name__ == '__main__':

    # No cycle in graph
    acyclic_graph = {
        'A' : ['C','D'],
        'B' : ['E','C'],
        'C' : ['D'],
        'D' : [],
        'E' : ['A','C']
    }

    print(topological_sort(acyclic_graph)) # prints ['B', 'E', 'A', 'C', 'D']

    # A cycle present between nodes (C, D and E)
    cyclic_graph = {
        'A' : ['C','D'],
        'B' : ['E','C'],
        'C' : ['D'],
        'D' : ['E'],
        'E' : ['A','C']
    }

    print(topological_sort(cyclic_graph)) # gives exception as cycle is present
