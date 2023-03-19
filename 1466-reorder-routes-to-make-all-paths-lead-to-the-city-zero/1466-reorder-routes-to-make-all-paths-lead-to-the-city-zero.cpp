class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        vector<vector<int>>back(n);
        for(auto i:c){
         adj[i[0]].push_back(i[1]);
            back[i[1]].push_back(i[0]);
           }
        queue<int>q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(auto it:adj[curr]){
                if(!vis[it]){
                    q.push(it);
                    ans++;
                 }
            }
                for(auto it:back[curr]){
                    if(!vis[it]){
                        q.push(it);
                    }
                }
       }
            return ans;
        
    }
};