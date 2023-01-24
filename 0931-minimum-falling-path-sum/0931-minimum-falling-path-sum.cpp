class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
               
                int a=(i+1 < 0 || i+1 >= n || j-1 <0 || j-1 >= n)? INT_MAX:dp[i+1][j-1];
                int b=(i+1 < 0 || i+1 >= n || j <0 || j >= n)? INT_MAX:dp[i+1][j];
                int c=(i+1 < 0 || i+1 >= n || j+1 <0 || j+1 >= n)? INT_MAX:dp[i+1][j+1];
                dp[i][j]=min(a,min(b,c))+matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};