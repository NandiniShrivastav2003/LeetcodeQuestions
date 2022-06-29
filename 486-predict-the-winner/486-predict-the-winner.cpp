class Solution {
public:
    bool PredictTheWinner(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
        }
        int val=solve(0,n-1,nums,dp);
        cout<<val;
        int diff=sum-val;
        if(diff>val)
        {
            return false;
        }
        else
        {
            return true;
        }
        
        
        
    }
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return nums[i];
        }
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int choice1=nums[i]+min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int choice2=nums[j]+min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));
        dp[i][j]=max(choice1,choice2);
        return dp[i][j];
    }
};