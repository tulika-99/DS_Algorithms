#include<bits/stdc++.h>
using namespace std;

/* 
 * Graph: Input/Ouput 
 *
 * Input : first line the number of nodes in graph - n
           second line number of edges in graph - m
           next m lines contain 2 spaced integers u and v denoting edge between u and v

 * Output : Displays the adjacency list representation of graph
            prints if the graph is cyclic or not.
 */

void init_graph(int a, vector<int> b[], bool c);
void display_graph(int a, vector<int> b[]);

/* There exits cycle in directed graph if and only if there exits back edge
 * example for the given given below graph
 *              1 -> 2 -> 3
 *              ^         |         3 -> 1 is back edge
 *              |_________|         
 * 
 * The idea to detect back edge is to use DFS traversal and to check if there
 * exits edges u -> v such that node v in the recursion stack of the DFS.
 *
 */

// recursive function to detect the cycle
bool detect_cycle_recursive(vector<int> adj_list[],
                            bool visited[],
                            bool recursion_stack[], 
                            int u) {
    if(visited[u] == false) {
        // traverse through the node u
        visited[u] = true;
        recursion_stack[u] = true;
        int v;
        for(int i = 0; i < adj_list[u].size(); i++) {
            v = adj_list[u][i];
            if(!visited[v]) {
                // check if you can find any cycles for v node
                if(detect_cycle_recursive(adj_list, visited, recursion_stack, v)) {
                    return true;
                }
            // if this connected node is already in recursion stack
            } else if(recursion_stack[v]) {
                return true;
            }
        }
    }
    // this particular node has been completely traversed 
    recursion_stack[u] = false;
    return false;
}

// detect cycle using DFS traversal for directed graph
bool detect_cycle(int nodes, vector<int> adj_list[], int start_node) {
    bool visited[nodes], recursion_stack[nodes];
    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
        recursion_stack[i] = false;
    }
    return detect_cycle_recursive(adj_list, visited, recursion_stack, start_node);
}

int main(int argc, char const *argv[]) {
    int nodes;
    cin >> nodes;
    vector<int> adj_list[nodes];
    init_graph(nodes, adj_list, false);
    display_graph(nodes, adj_list);
    
    if(detect_cycle(nodes, adj_list, 0)) {
        cout << "The graph is cyclic!" << endl;
    } else {
        cout << "The graph is acyclic!" << endl;
    }

    return 0;
}


// intializes the graph in adjacency list repersentation 
// input to the graph in number of u-v edges pairs
void init_graph(int nodes, vector<int> adj_list[], bool undirected) {
    int num_edges, u, v;
    cin >> num_edges;
    for(int i = 0; i < num_edges; i++) {
        cin >> u >> v; 
        // edge between u -> v
        adj_list[u].push_back(v);
        if(undirected) {
            // edge between v -> u
            adj_list[v].push_back(u);
        }
    }
}

// displays the graph adjacency list repersentation 
void display_graph(int nodes, vector<int> adj_list[]) {
    for(int i = 0; i < nodes; i++) {
        cout << i << " -> ";
        for(int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}

