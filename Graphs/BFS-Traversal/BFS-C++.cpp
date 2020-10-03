/*
BFS algorithm on graphs using adjacency lists
complexity: O(n+m) where n is the number of vertices and m is the number of edges

variables:
start: start of the bfs
graph: adjacency list
vis, lev: visited vertices and depth of the edges
parent: parent of the vertex
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int> > &graph, vector<bool> &vis, vector<int> &lev, vector<int> &parent)
{
    vis[start]=true;
    lev[start]=0;

    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto v: graph[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                lev[v]=lev[u]+1;
                parent[v]=u;

                q.push(v);
            }
        }
    }
}

int main()
{
    int n,m;
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

    parent[0]=0;
    bfs(0,graph,vis,lev,parent); //start bfs from 0

    for(int i=0;i<n;i++)
    {
        if(vis[i])
        {
            cout<<i+1<<" has been visited and its parent is "<<parent[i]+1<<"\n";
        }
        else
        {
            cout<<i+1<<" has not been visited\n";
        }
    }

    return 0;
}