class Solution {
public:
   
    
     void dfs(vector<int>adj[],int v,vector<int>&temp,int n,bool visited[]){
     
       visited[v]=true;
         
       for(int x:adj[v]){
            if( temp[x] == 0 ||visited[x] == false){
            temp[x]=1;
             
                dfs(adj,x,temp,n,visited);
                
            }
  }
  }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>adj[n];
        for(auto i:edges){
            int s=i[0];
            int t=i[1];
            adj[s].push_back(t);
        }
         bool visited[n];
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                 dfs(adj,i,temp,n,visited);
            }
        }
       
        for(int i=0;i<n;i++){
            if(temp[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};