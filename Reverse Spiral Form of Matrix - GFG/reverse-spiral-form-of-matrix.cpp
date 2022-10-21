//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
         vector<int>ans;
        int minr = 0, minc = 0;
        int maxr = R-1, maxc = C-1;
        int total = R*C, count = 0;
        
        while(count < total){
            //top
            for(int i=minc;i<=maxc and count < total ;i++){
                ans.push_back(a[minr][i]);
                count++;
            }
            minr++;
            
            //right
            for(int i=minr;i<=maxr and count < total;i++){
                ans.push_back(a[i][maxc]);
                count++;
            }
            maxc--;
            
            //bottom
            for(int i=maxc;i>=minc and count < total;i--){
                ans.push_back(a[maxr][i]);
                count++;
            }
            maxr--;
            
            //left
            for(int i=maxr;i>=minr and count < total;i--){
                ans.push_back(a[i][minc]);
                count++;
            }
            minc++;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends