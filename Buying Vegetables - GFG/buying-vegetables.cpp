//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minCost(int N, vector<int> dp[]) {
      for(int i=N-2;i>=0;i--){
         dp[i][0]=dp[i][0]+min(dp[i+1][1],dp[i+1][2]);
         dp[i][1]=dp[i][1]+min(dp[i+1][0],dp[i+1][2]);
         dp[i][2]=dp[i][2]+min(dp[i+1][1],dp[i+1][0]);
      }
return min(dp[0][0],min(dp[0][1],dp[0][2]));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> cost[N];
        int x, y, z;
        for(int i = 0;i < N;i++){
            cin>>x>>y>>z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }
        
        Solution ob;
        cout<<ob.minCost(N, cost)<<"\n";
    }
    return 0;
}
// } Driver Code Ends