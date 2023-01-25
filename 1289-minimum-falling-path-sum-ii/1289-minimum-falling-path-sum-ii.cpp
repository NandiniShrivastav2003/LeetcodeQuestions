class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                 int res=INT_MAX;
    for(int k=0;k<n;k++){
        if(j == k){
        continue;
        }
        res=min(res,dp[i-1][k]);
    }
                dp[i][j]=grid[i][j]+res;
            }
        }
        
        int ans=INT_MAX;
       
        for(int i=0;i<n;i++){
            ans=min(ans,dp[m-1][i]);
        }
        return ans;
        
    }
};