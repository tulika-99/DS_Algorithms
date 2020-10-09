/*
* Problem Statement: Find the number of connected components in an undirected graph
*  Given below is the solution of the same using Depth First Search
*/
#include<bits/stdc++.h>
using namespace std;
void DFS(int** G, int n, int sv, bool* visited, vector<int>&  ans)
{
     visited[sv] = true;
    ans.push_back(sv);
    for(int i = 0; i < n; i++)
    {
        if( i == sv)
            continue;
        if(G[sv][i] == 1)
        {
            if(visited[i] == false)
                DFS(G, n, i, visited, ans);
        }
    }
}
vector<vector<int>  > ConnectedComponents(int** G, int V)
{
     vector<vector<int>  > components;
     bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

 for(int i = 0; i < V; i++)
  {
      if( visited[i] == false )
         {
             vector<int> ans;
               DFS(G, V, i, visited,  ans);
               components.push_back(ans);
         }
  }
    delete [] visited;
    return components;
}
int main()
{
    int V, E;
    cout<<"Enter the number of vertices and edges:\n";
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
    cout<<"Enter the edges:\n";
    int a, b;
    for(int i = 0; i < E; i++)
    {
        cin>>a>>b;
        G[a][b] = 1;
        G[b][a] = 1;
    }

vector<vector<int>  > components = ConnectedComponents(G, V);
vector<vector<int>  >::iterator it1 = components.begin();
  cout<<"Total connected components = "<<components.size()<<endl;
  cout<<"These connected components are:"<<endl;
while(it1 != components.end() )
{
    vector<int> comp = *it1;
    vector<int>::iterator it2 = comp.begin();
    while( it2 != comp.end() )
    {
        cout<<*it2<<" ";
        it2++;
    }
   if(it1 <= components.end()-2)
     cout<<endl;
    it1++;
}

 for (int i = 0; i < V; i++)
  {
    delete [] G[i];
  }
    delete [] G;
  return 0;
}
