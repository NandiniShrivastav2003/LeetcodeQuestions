// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsrec(vector<int>adj[],bool vis[],bool recst[],int i){
        vis[i]=true;
        recst[i]=true;
        for(int v:adj[i]){
            if(vis[v] == false){
                if(dfsrec(adj,vis,recst,v) == true){return true;}
            }
                else if(recst[v] == true){return true;}
            
        }
        recst[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V]={false};
        bool recst[V]={false};
        for(int i=0;i<V;i++){
            if(vis[i] == false){
                if(dfsrec(adj,vis,recst,i) == true){return true;}
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends