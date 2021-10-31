#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& vis){
        vis[node] = true;
        for(int& el:adj[node]){
            if(!vis[el]) dfs(el,adj,vis);
        }
    }
	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	
	    vector<bool> vis(V,false);
        vector<int> degree(V,0);
        
        int oddCount = 0;
        int node = -1;
        for(int i=0; i<V; i++){
            degree[i] = adj[i].size();
            if(degree[i] & 1) ++oddCount;
            if(degree[i] != 0) node = i;
        }
        
        
        if(node == -1) return 2;
        
        dfs(node,adj,vis);
        
        for(int i=0; i<V; i++){
            if(vis[i] == false && degree[i] > 0) return 0;
        }
        
        if(oddCount == 0) return 2;
        else if(oddCount == 2) return 1;
        else return 0;
  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends
/*
task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoting as V and adjacency list of graph denoting as adj and returns 1 if graph contains Eulerian Path, 2 if graph contains Eulerian Circuit 0 otherwise.
*/