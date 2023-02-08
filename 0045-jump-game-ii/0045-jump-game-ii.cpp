class Solution {
public:
   
    int canjump(vector<int>&nums,int i,int c,vector<int>&dp){
        if(i == nums.size()-1){
            return 0;
        }
         if(i>=nums.size()){
            return 0;
        }
      
        if(dp[i] != 100001){
            return dp[i];
        }
       for(int j=1;j<=nums[i];j++){
           dp[i]=min(dp[i],1+canjump(nums,i+j,c,dp));
       }
        return dp[i];
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),100001);
       int x=canjump(nums,0,0,dp); 
        return x;
        
    }
};