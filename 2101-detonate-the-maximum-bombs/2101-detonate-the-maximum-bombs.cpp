class Solution {
public:
    void dfs(vector<bool>&vis,vector<int>adj[],int i){
        vis[i]=true;
        for(auto v:adj[i]){
            if(vis[v] == false){
                dfs(vis,adj,v);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        long long int d,x1,y1,x2,y2,r1,r2;
        long long int  ans=INT_MIN;
      
        long long int count=0;
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                     x1=bombs[i][0];
                    y1=bombs[i][1];
                    x2=bombs[j][0];
                     y2=bombs[j][1];
                     r1=bombs[i][2];
                   r2=bombs[j][2];
                    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                    if(d <= r1 * r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            dfs(vis,adj,i);
            for(int i=0;i<n;i++){
                if(vis[i] == true){
                    count++;
                }
            }
            ans=max(ans,count);
            count=0;
            
        }
return ans == INT_MIN ?1:ans;
    }
};