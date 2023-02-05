class Solution {
public:
    int c=0;
    int  calSub(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(j<0){
            c++;
            return 1;
        }
        if(i<0){
          return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
         dp[i][j]=calSub(s,t,i-1,j-1,dp)+calSub(s,t,i-1,j,dp);
        }
        else{
           dp[i][j]= calSub(s,t,i-1,j,dp);
        }
        return dp[i][j];
        
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
      
        vector<vector<int>>dp(m,vector<int>(n,-1));

     int x= calSub(s,t,m-1,n-1,dp);
     //        for(int i=0;i<m;i++){
     //     for(int j=0;j<n;j++){
     //         cout<<dp[i][j]<<" ";
     //     }
     //     cout<<endl;
     // }
       return x;
    }
};