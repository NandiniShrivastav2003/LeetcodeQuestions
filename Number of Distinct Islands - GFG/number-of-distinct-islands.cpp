//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void distinctIsland(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&vis,int p,int q,
  vector<pair<int,int>>&v){
      if(i<0 || j<0  || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0 || vis[i][j] == 1){
          return ;
      }
     
          vis[i][j] =1;
  v.push_back({i-p,j-q});
      distinctIsland(grid,i+1,j,vis,p,q,v);
      distinctIsland(grid,i-1,j,vis,p,q,v);
      distinctIsland(grid,i,j+1,vis,p,q,v);
      distinctIsland(grid,i,j-1,vis,p,q,v);
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
       set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<pair<int,int>>v;
                if(grid[i][j] == 1  && vis[i][j] == 0){
                    distinctIsland(grid,i,j,vis,i,j,v);
                  st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends