class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
             if(p[i-1] == '*'){
                dp[0][i]=dp[0][i-1]&& 1;
            }
            else{
                dp[0][i]=0;
            }
        }   
        for(int i=1;i<=m;i++){
            if(s[i-1] == '*'){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1] == p[j-1] || s[i-1] == '?'
                    || p[j-1] == '?'
                  ){
                    dp[i][j]=dp[i-1][j-1];
                }
                 else if(s[i-1] == '*' 
                      || p[j-1] == '*'
                       ){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[m][n];
        
    }
};