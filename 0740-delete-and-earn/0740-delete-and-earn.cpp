class Solution {
public:
    int  ans(vector<int>nums,int  dp[]){
        for(int i=0;i<nums.size();i++){
            if(i < 0){
            return 0;
        }
           
            dp[i]=max((i-2 < 0 ? 0 : dp[i-2])+nums[i],(i-1 < 0 ? 0: dp[i-1]));
        }
        return dp[nums.size()-1];
    }
    int deleteAndEarn(vector<int>& nums) {
//         int res=-1;
//         for(int i=0;i<nums.size();i++){
//             res=max(res,nums[i]);
//         }
       
//         int dp[res+1];
//         unordered_map<int,int>mp;
        
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]+=nums[i];
//         }
       
//         for(int i=0;i<=res;i++){
//             if(mp.find(i) != mp.end()){
//                 dp[i]=mp[i];
//             }
//             else{
//                 dp[i]=0;
//             }
           
//         }
//         int fin[res+1];
//       return ans(dp,fin,res+1);
          int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;
        int dp[n];
         return ans(values,dp);
        
    }
};