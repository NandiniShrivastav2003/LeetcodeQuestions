class Solution {
public:
    int ans(vector<int>nums,int dp[],int i){
        for(int i=0;i<nums.size();i++){
        if(i<0){
            return 0;
        }
        dp[i]=max((i-2 < 0 ? 0 :dp[i-2]) + nums[i] ,(i -1 < 0 ? 0 :dp[i-1]));
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int>ans1;
        vector<int>ans2;
        for(int i=0;i<nums.size()-1;i++){
            ans1.push_back(nums[i]);
        }
         for(int i=1;i<nums.size();i++){
            ans2.push_back(nums[i]);
        }
        int dp1[nums.size()-1];
        int dp2[nums.size()-1];
        return max(ans(ans1,dp1,0),ans(ans2,dp2,0));
        
    }
};