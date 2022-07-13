// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
    const int mod=1e9+7;
      int dp[n+1][r+1];
      dp[0][0]=1;
      for(int i=1;i<=n;i++){
          dp[i][0]=1;
      }
      for(int i=1;i<=r;i++){
          dp[0][i]=0;
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=r;j++){
              if( i == j){
                  dp[i][j]=1;
              }
              else{
                  dp[i][j]=((dp[i-1][j-1]%mod)+(dp[i-1][j]%mod))%mod;
              }
          }
      }
      return dp[n][r];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends