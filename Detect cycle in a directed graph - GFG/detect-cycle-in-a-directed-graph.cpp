//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>indeg(v,0);
        queue<int>q;
        for(int i=0;i<v;i++){
            for(int x:adj[i]){
                indeg[x]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:adj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(ans.size() < v){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

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