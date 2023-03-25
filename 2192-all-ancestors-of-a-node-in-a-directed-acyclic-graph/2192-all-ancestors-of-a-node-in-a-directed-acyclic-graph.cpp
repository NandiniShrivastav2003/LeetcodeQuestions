class Solution {
public:
    void dfs(vector<vector<int>>&adj,int u,vector<int>&temp,vector<int>&vis){
        vis[u]=true;
        for(auto v:adj[u]){
            if(!vis[v]){
            temp.push_back(v);
            dfs(adj,v,temp,vis);
        }
        }
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i:edges){
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>temp;
            vector<int>vis(n,false);
            dfs(adj,i,temp,vis);
            sort(temp.begin(),temp.end());
            
            ans.push_back(temp);
        }
        return ans;
   }
};