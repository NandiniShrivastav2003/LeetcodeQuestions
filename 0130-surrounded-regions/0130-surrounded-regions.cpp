class Solution {
public:
    void convert(vector<vector<char>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 'T'){
                    grid[i][j]='O';
                }
                else{
                    grid[i][j]='X';
                }
            }
        }
    }
   void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 'O') {
            return;
        }
        grid[i][j] = 'T';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();int n=board[0].size();
        for(int i=0;i<n;i++){
if(board[0][i] == 'O'){
  eraseIslands(board,0,i);
}
            if(board[m-1][i] == 'O'){
          eraseIslands(board,m-1,i);
            }
        }
        for(int i=0;i<m;i++){
             if(board[i][0] == 'O'){
                 
            eraseIslands(board,i,0);
             }
             if(board[i][n-1] == 'O'){
           eraseIslands(board,i,n-1);
             }
        }
        convert(board);
        return ;
    }
};