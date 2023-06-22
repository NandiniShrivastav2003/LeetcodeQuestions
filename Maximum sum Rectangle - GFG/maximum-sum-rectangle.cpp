//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kadane(vector<int>&arr){
      int ans=0;
      int maxi=INT_MIN;
      for(int i=0;i<arr.size();i++){
          ans+=arr[i];
          maxi=max(maxi,ans);
          if(ans<0){
              ans=0;
          }
      }
      return maxi;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans=INT_MIN;
        for(int k=0;k<C;k++){
        vector<int>arr(R,0);
       for(int i=k;i<C;i++){
           for(int j=0;j<R;j++){
               arr[j]+=M[j][i];
           }
           ans=max(ans,kadane(arr));
           
       }
        }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends