class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int val=4;
        vector<int>adj[n+1];
        vector<int>res;
        for(auto it:paths){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n+1,-1); 
       for(int node=1;node<=n;node++){
           if(ans[node] == -1){
              ans[node]=1;
               queue<int>q;
               q.push(node);
               while(!q.empty()){
                   auto curr=q.front();
                   q.pop();
            for(int  i:adj[curr]){
                if(ans[i] == -1){
                    ans[i]=max(1,(ans[curr]+1)%5);
                q.push(i);
                    
                }
                else if(ans[i] == ans[curr]){
                     ans[i]=max(1,(ans[curr]+1)%5);
                }
            
            }
        }
           }
       }
        for(int i=1;i<=n;i++){
            res.push_back(ans[i]);
        }
        return res;
    }
};