class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& it) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(m[i] == -1){
                continue;
            }
            mp[m[i]].push_back(i);
        }
        int ans=0;
     queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                int dur=b+it[a];
                ans=max(ans,dur);
                for(auto i:mp[a]){
                    q.push(make_pair(i,dur));
                }
            }
        }
        return ans;
        
    }
};