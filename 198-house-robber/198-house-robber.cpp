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
    int rob(vector<int>& nums) {
        int dp[nums.size()];
       return  ans(nums,dp);
    }
};