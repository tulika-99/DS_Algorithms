#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int src; //source
    int dest; //destination
    int weight;
};
bool comp(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}

int getp(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    return getp(parent[v],parent);
}

Edge* krus(Edge* edges,int V,int E)
{
    sort(edges,edges+E,comp);
    Edge* output=new Edge[V-1];
    int *parent=new int[V];
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    int count=0,i=0;
    while(count<V-1)
    {
        Edge curr=edges[i];
        int sp=getp(curr.src,parent); //source parent
        int dp=getp(curr.dest,parent); //destination parent
        
        if(sp!=dp)
        {
            output[count]=curr;
            count+=1;
            parent[sp]=dp;
        }
        i+=1;
    }
    return output;
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
   Edge* edges=new Edge[E]; 
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edges[i].src=s;
        edges[i].dest=d;
        edges[i].weight=w;
        
    }
    Edge* output=krus(edges,V,E);
    
    for(int i=0;i<V-1;i++)
        
    {
        if(output[i].src<output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight;
        }
        else
        {
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight;
        }
        cout<<endl;
    }

  

  return 0;
}
