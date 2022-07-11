class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dp[m][n];
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0 || matrix[i][j] == '0'){
                    dp[i][j]=matrix[i][j] - '0';
                    
                }
               else{
                
                   dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
                   
               }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};