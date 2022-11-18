class Solution {
public:
    int mod=1e9+7;
    long fun(int i,int j,int n, vector<vector<vector<long>>>&dp){
        if(i < 0 || i>=4 || j<0 || j>=3 || (i == 3 && j!= 1)){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(dp[i][j][n] != -1){
            return dp[i][j][n];
        }
        dp[i][j][n]=fun(i-2,j-1,n-1,dp)%mod+
            fun(i-1,j-2,n-1,dp)%mod+
            fun(i-2,j+1,n-1,dp)%mod+
            fun(i-1,j+2,n-1,dp)%mod+
            fun(i+1,j-2,n-1,dp)%mod+
            fun(i+1,j+2,n-1,dp)%mod+
            fun(i+2,j-1,n-1,dp)%mod+
            fun(i+2,j+1,n-1,dp)%mod;
        return dp[i][j][n];
    }
    int knightDialer(int n) {
       vector<vector<vector<long>>>dp(4,vector<vector<long>>(3,vector<long>(n+1,-1)));
        long ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans=(ans+fun(i,j,n,dp))%mod;
            }
        }
        return (int)ans;
    }
};