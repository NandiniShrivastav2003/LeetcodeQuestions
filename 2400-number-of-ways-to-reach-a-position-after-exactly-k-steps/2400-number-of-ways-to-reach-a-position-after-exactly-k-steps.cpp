class Solution {
public:

  int f(int s, int i, int j, int k, int e, vector<vector<int>>& dp, int m)
  {
    if(i==k && j==e) return 1; // returns 1 if in k steps it has reached to the end point.
    else if(i==k && j!=e) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int l = 0, r = 0;
    l = f(s, i+1, j-1, k, e, dp, m); // it will move 1 step left
    r = f(s, i+1, j+1, k, e, dp, m); // it will move 1 step right   

    
    return dp[i][j] = (l+r)%m; // total ways to reach end point 
  }

    int numberOfWays(int s, int e, int k) {
        
      vector<vector<int>> dp(k+1, vector<int> (10000, -1));
      int m =(1000000000 + 7);
      s = s+1000; // shifting of coordinates to make -ve integers +ve.
      e = e+1000;
      return f(s, 0, s, k, e, dp, m)%m;
    }
};