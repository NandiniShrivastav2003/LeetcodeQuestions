class Solution {
public:
    int mod=1e9+7;
    int countStrings(vector<int>&dp,int zero,int one,int n){
        if(n == 0){
            return 1 ;
        }
        if(n<0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
         dp[n]=(countStrings(dp,zero,one,n-zero) % mod+
        countStrings(dp,zero,one,n-one) %mod)%mod;
        return dp[n];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        int ans=0;
        for(int i=low;i<=high;i++){
           ans= (ans+countStrings(dp,zero,one,i)%mod)%mod;
        }
        return ans;
    }
};