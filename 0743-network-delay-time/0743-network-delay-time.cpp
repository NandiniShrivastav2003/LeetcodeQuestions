class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=0;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=1;i<n;i++){
            for(auto j:times){
                int u=j[0];
                int v=j[1];
                int wt=j[2];
             if(dist[u] != INT_MAX && dist[v] > dist[u]+wt){
                 dist[v]=dist[u]+wt;
             }
            }
        }
        for(int i=1;i<dist.size();i++){
            ans=max(ans,dist[i]);
        }
    return ans==INT_MAX?-1:ans;
    }
};