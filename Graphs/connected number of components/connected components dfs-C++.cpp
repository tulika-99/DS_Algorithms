/*
DFS algorithm on graphs using adjacency lists
complexity: O(n+m) where n is the number of vertices and m is the number of edges

This algorithm runs a dfs traversal on a graph and find the number of connected components. It additionally finds the parents and depth of the vertices.
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int> > &graph, vector<bool> &vis, vector<int> &lev, vector<int> &parent)
{
    vis[start]=true;

    for(auto u: graph[start])
    {
        if(!vis[u])
        {
            dfs(u, graph, vis,lev, parent);
            parent[u]= start;
            lev[u]= lev[start]+1;
        }
    }
}

int main()
{
    int n, m, components=0;
    cin>>n>>m;

    vector<vector<int> > graph(n);
    vector<bool> vis(n);
    vector<int> lev(n), parent(n,-1);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            parent[i]=i; //as it is the starting node
            dfs(i,graph,vis,lev,parent);
            components++;
        }
    }

    cout<<"No. of connected components= "<<components<<endl;

    return 0;
}