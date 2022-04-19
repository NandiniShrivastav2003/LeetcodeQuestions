// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[],bool visited[],int parent,int u){
        visited[u]=true;
        for(int i:adj[u]){
            if(visited[i] == false){
               if( dfs(adj,visited,u,i)== true){
                    return true;
                }
            }
                else if(i != parent){
                    return true;
                }
            
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        bool visited[v]={0};
        for(int i=0;i<v;i++){
            if(visited[i] == false){
            if(dfs(adj,visited,-1,i) == true){
                return true;
            }
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends