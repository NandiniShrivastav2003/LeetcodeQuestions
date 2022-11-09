class Solution {
public:
     int lcs(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                   // cout<<text1[i-1]<<"";
                    dp[i][j]=text1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    int minimumDeleteSum(string s1, string s2) {
        int seqval= lcs(s1,s2);
        int sum=0;
        for(int i=0;i<s1.size();i++){
            sum+=s1[i];
        }
        for(int i=0;i<s2.size();i++){
            sum+=s2[i];
        }
        return sum-2*seqval;
    }
};