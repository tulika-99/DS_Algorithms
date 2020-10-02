#include<bits/stdc++.h>
using namespace std;
int vis[1001];
int in[1001],low[10001];
vector<int >arr[1001];
int timer;

void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;

    for(int child : arr[node])
    {
        if(child==par)
            continue;

        if(vis[child]==1 )
        {
            //Back Edge....
            low[node]=min(low[node],in[child]);

        }

        else
        {

            dfs(child,node);

            if(low[child]>in[node])
                cout<<node<<" - "<<child<<"get bridge \n";

            low[node]=min(low[node],low[child]);
        }

    }


}

int main()
{

int n,m;
cout<<"Enter Number of vertex and number of Edges\n";
    cin>>n>>m;
  //
    cout<<"Enter Vertex\n";
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    dfs(1,-1);
}
