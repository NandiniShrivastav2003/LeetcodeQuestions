class Solution {
public:

     void dfs(int v,vector<vector<int>>&adj,vector<bool>&visited){
     
       visited[v]=true;
       for(int x:adj[v]){
            if(visited[x] == false){
            
            
                dfs(x,adj,visited);
                
            }
  }
  }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1 ){
            return -1;
        }
        vector<vector<int>>adj(n);
        for(auto v:connections){
           adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back( v[0]);
        }
        int ans=0;
vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
            dfs(i,adj,visited);
            ans++;
            }
        }
         return ans-1;
       
  
    }
};