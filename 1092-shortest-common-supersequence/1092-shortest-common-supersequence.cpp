class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
            int m=text1.size();
        int n=text2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
        string s="";
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    s+=text1[i-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
         string ans="";
        int len=m+n-dp[m][n];
        char arr[len];
        while(m>0 && n>0){
            if(text1[m-1] == text2[n-1]){
                arr[len-1]=text1[m-1];
                ans+=text1[m-1];
                m--;
                n--;
            }
            else if(dp[m-1][n] > dp[m][n-1]){
                arr[len-1]=text1[m-1];
                ans+=text1[m-1];
                m--;
            }
            else{
                arr[len-1]=text2[n-1];
                ans+=text2[n-1];
                n--;
            }
            len-=1;
        }
        while(m>0){
            arr[len-1]=text1[m-1];
            ans+=text1[m-1];
            len--;
            m--;
        }
        while(n>0){
            arr[len-1]=text2[n-1];
            ans+=text2[n-1];
            len--;
            n--;
        }
       
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};