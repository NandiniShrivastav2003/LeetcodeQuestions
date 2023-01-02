class Solution {
public:
    int countPairs(vector<int>& arr) {
       unordered_map<int,int>mp;
        int ans=0;
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        for(auto x:arr){
            for(int i=0;i<=21;i++){
                int z=1<<i;
                int y=z-x;
                if(y > x){
                    break;
                }
                if(mp.find(y) != mp.end()){
                    ans+=mp[y];
                }
                ans=ans%mod;
            }
            mp[x]++;
        }
        return ans;
    }
};