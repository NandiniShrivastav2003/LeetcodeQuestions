class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>indegree(n,0);
        for(auto i:edges){
            if(i != -1){
            indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            int v=edges[node];
            if(v == -1){
                continue;
            }
            --indegree[v];
               if(indegree[v] == 0){
                   q.push(v);
               } 
            }
      
        int ans=-1;
        for(int i=0;i<n;i++){
            int count=1;
            if(!vis[i]){
                int j=i;
                vis[i]=1;
                while( i != edges[j]){
                    vis[edges[j]]=1;
                    j=edges[j];
                    count++;
                }
                  ans=max(ans,count);
            }
          
        }
        return ans;
    }
};