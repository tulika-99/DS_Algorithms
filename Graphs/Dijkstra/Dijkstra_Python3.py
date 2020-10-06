"""
Dijkstra's algorithm finds the shortest path from one node to all other nodes
in a weighted graph.

Algorithm:

Initialize a Map of Node which shows minimum cost to reach from starting node
and mark them Infinity but mark start node as 0 as no cost required.
Initialize a Map of Node to track the changes in a node cost.
Create a Set to mark all the nodes which have already been explored

We will explore the node which has the minimum cost till now
Create a Priority queue which will be used to fetch the node with the minimum
cost.

while the priority queue is not empty:
Pop the element
    (Check if it is the latest vesrion
    if False then discard)
Explore all its neighbours
    (if neighbour not in visited
    update its cost if required
    update cost version of node
    make an entry in the priority queue)
"""

# N : Number of Nodes
# E : Number of Edges
# Time Complexity : O(N∗lg(N) + E∗lg(N))
# Space Complexity : O(N)

import heapq

def dijkstra(graph_adjacency_list, start_node):

    # Initially, it costs an unknown amount to get anywhere
    # other than the start_node (which we can get to for free)
    cost_to_get_to = { node : float('inf') for node in graph_adjacency_list }
    cost_to_get_to[start_node] = 0

    # keep a counter to discard the old cost of nodes in priority queue
    node_cost_version = { node : 0 for node in graph_adjacency_list }

    # Track which nodes we've already dequeued -- we know
    # we've already found the shortest path to each of them
    # (This is the "checkmark" from our table)
    dequeued_nodes = set()

    # Priority queue ordering cities by the cost to get to them
    priority_queue = []

    for node in graph_adjacency_list:
        heapq.heappush(priority_queue, (cost_to_get_to[node], node, node_cost_version[node]))

    while len(priority_queue) > 0:

        # Dequeue the next node from our priority queue
        cheapest_cost, cheapest_node, cheapest_node_queue_version = heapq.heappop(priority_queue)

        # discard older version of node cost
        if cheapest_node_queue_version < node_cost_version[cheapest_node]:
            continue

        dequeued_nodes.add(cheapest_node)

        # Update cost_to_get_to for neighbouring nodes
        for neighbour, edge_cost in graph_adjacency_list[cheapest_node]:

            # Nodes we dequeued earlier can be skipped
            if neighbour in dequeued_nodes:
                continue

            # Can we get there more cheaply via this neighbour node?
            if cost_to_get_to[cheapest_node] + edge_cost < cost_to_get_to[neighbour]:

                # Update the cost to reach the node
                cost_to_get_to[neighbour] = cost_to_get_to[cheapest_node] + edge_cost

                # Update the node node_cost_version
                node_cost_version[neighbour] += 1

                # Push the updated cost to reach this node in the priority queue
                heapq.heappush(priority_queue, (cost_to_get_to[neighbour], neighbour, node_cost_version[neighbour]))

    return cost_to_get_to

# Driver Code
if __name__ == '__main__':
    graph_adjacency_list = {
        'A' : [('B',3), ('C',7), ('D',15), ('E',10)],
        'B' : [('A',3), ('C',3)],
        'C' : [('B',3), ('A',7), ('E',2)],
        'D' : [('A',15), ('E',2)],
        'E' : [('D',2), ('A',10), ('C',2)],
        'F' : []
    }
    print("Shortest Distance")
    for start in graph_adjacency_list:
        print("Starting Node {} => {}".format(start,dijkstra(graph_adjacency_list, start)))

    """
    # Output
    Shortest Distance
    Starting Node A => {'A': 0, 'B': 3, 'C': 6, 'D': 10, 'E': 8, 'F': inf}
    Starting Node B => {'A': 3, 'B': 0, 'C': 3, 'D': 7, 'E': 5, 'F': inf}
    Starting Node C => {'A': 6, 'B': 3, 'C': 0, 'D': 4, 'E': 2, 'F': inf}
    Starting Node D => {'A': 10, 'B': 7, 'C': 4, 'D': 0, 'E': 2, 'F': inf}
    Starting Node E => {'A': 8, 'B': 5, 'C': 2, 'D': 2, 'E': 0, 'F': inf}
    Starting Node F => {'A': inf, 'B': inf, 'C': inf, 'D': inf, 'E': inf, 'F': 0}
    """
