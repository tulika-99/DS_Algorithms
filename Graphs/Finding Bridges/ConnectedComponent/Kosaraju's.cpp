//This Algorithm is used for counting strongly connected components in directed graph
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>arr[],int par, stack<int>&st,bool visited[])
{
    visited[par]=true;

    for(int child : arr[par])
    {

        if(!visited[child])
        {
            dfs(arr,child,st,visited);
        }
    }
    st.push(par);      //storing parents in stack
}
void dfs_util(int par,vector<int>transpose[],bool visited[])
{

    visited[par]=true;
    for(int child : transpose[par])
    {
        if(!visited[child])
            dfs_util(child,transpose,visited);
    }
}
int Kosaraju(int V,vector<int>arr[])
{
    stack<int>st;
    bool visited[V];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<V;i++)
    {

        for(int j=0;j<arr[i].size();j++)
        {
            if(visited[arr[i][j]]==false)
            {
                dfs(arr,arr[i][j],st,visited);
            }
        }
    }
    //Transposing the graph

    vector<int>transpose[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {

            transpose[arr[i][j]].push_back(i);
        }
    }
    int connected_count=0;
    memset(visited,false,sizeof(visited));
    while(!st.empty())
    {

        int tmp=st.top();
        st.pop();
        if(visited[tmp]==false)
        {
            dfs_util(tmp,transpose,visited);
            connected_count++;
        }
    }
    return connected_count;
}
int main()
{

    int n,m;
    cin>>n>>m;     //Enter number of vertex and number of edges
    vector<int>arr[n];

    while(m--)
    {

        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);     //Creating directed graph
    }

    cout<<"Number of Strongly Connected Components\n";
    cout<<Kosaraju(n,arr);
}
