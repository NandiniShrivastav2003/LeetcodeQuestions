class Solution {
public:
   
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
       int firstReceived;
        int waiting;
       int resend;
        int ans=0;
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;
            for(auto j:adj[node]){
                
                dist[j]=min(dist[j],dist[node]+1);
                if(!vis[j]){
                    q.push(j);
                }
               
            }
            
        }
        vector<int>idle;
        for(int i=0;i<n;i++){
           firstReceived=(dist[i]*2);
          waiting=(firstReceived-1);
            if(patience[i] != 0){
           resend=(waiting/patience[i]);
            }
            else{
                resend=0;
            }
          idle.push_back(firstReceived+patience[i]*resend);
        }
        for(auto j:idle){
            ans=max(ans,j);
        }
           
       
        return ans+1;
    }
};