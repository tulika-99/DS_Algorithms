//Depth First Search (a graph traversal algorithm) implementation in C++
#include<bits/stdc++.h>
using namespace std;

void DFS(int** G, int n, int sv, bool* visited)
{
    cout<<sv<<" ";
    visited[sv] = true;
    for(int i = 0; i < n; i++)
    {
        if( i == sv)
            continue;
        if(G[sv][i] == 1)
        {
            if(!visited[i])
                DFS(G, n, i,visited);
        }
    }
}
int main() {
    int V, E, s;
    cout<<"Enter the number of vertices and edges : ";
    cin >> V >> E;
    int** G = new int*[V];
    for(int i = 0; i < V; i++)
    {
        G[i] = new int[V];
        for(int j = 0; j < V; j++)
        {
            G[i][j] = 0;
        }
    }
    int a, b;
    cout<<"Enter the edges of the directed graph:\n";
    for(int i = 0; i < E; i++)
    {
        cin>>a>>b;
        G[a][b] = 1;
    }
     bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    cout<<"Enter the source vertex: ";
    cin>>s;
    cout<<"Traversal order :"<<endl;
DFS(G, V, s,visited);
delete [] visited;
for(int i = 0; i < V; i++)
{
    delete [] G[i];
}
    delete [] G;
  return 0;
}
