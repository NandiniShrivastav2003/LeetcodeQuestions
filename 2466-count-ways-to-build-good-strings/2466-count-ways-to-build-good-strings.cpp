class Solution {
public:
    int mod = 1e9 + 7;
    int getcount(vector<int>&dp , int zero , int one , int n)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (getcount(dp,zero,one,n-zero) % mod + getcount(dp,zero,one,n-one) % mod) % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one)
    {
        int ans = 0;
        vector<int>dp(high+1,-1);
        
        for(int i = low ; i <= high ; i++)
        {
            ans = (ans + getcount(dp , zero , one , i) % mod) % mod;
        }
        return ans;
    }
};