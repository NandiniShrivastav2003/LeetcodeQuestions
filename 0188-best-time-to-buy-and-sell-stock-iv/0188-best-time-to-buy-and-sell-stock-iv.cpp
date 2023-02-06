class Solution {
public:
     int profit(vector<vector<vector<int>>>&dp,vector<int>&prices,int ind,int buy,int k){
          if(k == 0 || ind == prices.size()){
             return 0;
         }
        
        
        if(dp[ind][buy][k] != -1){
            return dp[ind][buy][k];
        }
        if(buy){
            dp[ind][buy][k]=max(-prices[ind]+profit(dp,prices,ind+1,0,k),profit(dp,prices,ind+1,1,k));
        }
        else{
            dp[ind][buy][k]=max(prices[ind]+profit(dp,prices,ind+1,1,k-1),profit(dp,prices,ind+1,0,k));
        }
        return dp[ind][buy][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return profit(dp,prices,0,1,k);
    }
};