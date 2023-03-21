class Solution {
public:
    int c=0;
    void dfs( vector<vector<int>>&adj,vector<int>&vis,int u){
      vis[u]=1;
        c++;
    for(int v:adj[u]){
        if(vis[v] == 0){
        dfs(adj,vis,v);
        }
    }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        vector<int>vis(n,0);
        for(int i:res){
            vis[i]=1;
            
        }
        vector<vector<int>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(adj,vis,0);
        return c;
    }
};