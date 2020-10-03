#include<bits/stdc++.h>
using namespace std;

/*
 * Graph input/output
 * Input : first line the number of nodes in graph - n
           second line number of edges in graph - m
           next m lines contain 2 spaced integers u and v denoting edge between u and v

 * Output : Displays the adjacency list representation of graph
            prints the topological sort order of the graph
 */

void init_graph(int a, vector<int> b[], bool c);
void display_graph(int a, vector<int> b[]);

/* Topological ordering is ordering in which u appears v if u has higher
 * priority than the v. Such kind of ordering helps in solving many real life
 * problem such as job scheduling.
 */

/* Assuming that the given graph is DAG, we can simply apply DFS to obtain the 
 * order. However we need to note the vertices that finish the DFS explorations
 * first andd then reverse those set of vertices.
 */
void dfsTopologicalOder(vector<int> adj_list[], bool visited[], int u, 
                        vector<int> &reverse_topological_order) {
    visited[u] = true;
    for(int i = 0; i < adj_list[u].size(); i++) {
        int v = adj_list[u][i];
        /* search depth for adjacent nodes */
        if(!visited[v]) {
            dfsTopologicalOder(adj_list, visited, v, 
                               reverse_topological_order);
        }
    }
    /* node u has completed searching for its depth 
     * thus node u has no more dependence for search
     */
    reverse_topological_order.push_back(u);
}

/* returns the topological sorted order given a DAG */
vector<int> TopologicalSort(int nodes, vector<int> adj_list[]) {
    bool visited[nodes];
    vector<int> order;
    for(int i = 0; i < nodes; i++) {
        visited[i] = false;
    }
    for(int i = 0; i < nodes; i++) {
        if(visited[i] == false) {
            dfsTopologicalOder(adj_list, visited, i, order);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}


int main(int argc, char const *argv[]) {
    int nodes;
    cin >> nodes;
    vector<int> adj_list[nodes];
    init_graph(nodes, adj_list, false);
        
    vector<int> order = TopologicalSort(nodes, adj_list);
        
    cout << "The topological sort order is " << endl;
    for(int i = 0; i < order.size(); i++) {
        cout << order[i] << " ";
    }
    cout << endl;

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

