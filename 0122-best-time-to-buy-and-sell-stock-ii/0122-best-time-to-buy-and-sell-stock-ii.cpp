class Solution {
public:
    int profit(vector<vector<int>>&dp,vector<int>&prices,int ind,int buy){
        if(ind == prices.size()){
            return 0;
        }
        
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        if(buy){
            dp[ind][buy]=max(-prices[ind]+profit(dp,prices,ind+1,0),profit(dp,prices,ind+1,1));
        }
        else{
            dp[ind][buy]=max(prices[ind]+profit(dp,prices,ind+1,1),profit(dp,prices,ind+1,0));
        }
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return profit(dp,prices,0,1);
    }
};