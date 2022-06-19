class Solution {
public:
    int LCS(string word1,string word2){
        int m=word1.size();
        int n=word2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
          
        int lcs=LCS(word1,word2);
        return word1.size()-lcs+word2.size()-lcs;
        
    }
};