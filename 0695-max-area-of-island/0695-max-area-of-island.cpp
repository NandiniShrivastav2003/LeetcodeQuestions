class Solution {
public:
    int ans;
    int res=0;
     void eraseIslands(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
         ans++;
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               
                if (grid[i][j] == 1) {
             
                    eraseIslands(grid, i, j);
        
                    res=max(res,ans);
                 
                    ans=0;
                }
            }
        }
        return res;
    }
};