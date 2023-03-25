class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>v(n+1);
        for(vector<int>i:roads){
            v[i[0]].push_back({i[1],i[2]});
            v[i[1]].push_back({i[0],i[2]});
        }
        queue<int>q;
        q.push(1);
        vector<int>vis(n+1);
        int mini=INT_MAX;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=1;
            for(auto i:v[curr]){
               
                    mini=min(mini,i.second);
                if(!vis[i.first]){
                  vis[i.first]=1;
                q.push(i.first);
                }
            }
            
        }
        
        return mini;
    }
};