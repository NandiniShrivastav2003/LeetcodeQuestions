class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid , int row , int col , int& sum){
        if(row<0 or row>=grid.size() or col<0 or grid[0].size()<=col or grid[row][col]==0){ //all condition where we can't visited
            return ;
        }
        int temp = grid[row][col];
        sum+=temp;
        ans = max(ans , sum);
        grid[row][col]=0;  // to avoid visiting the same cell more than once 
        dfs(grid ,row-1 , col ,sum);
        dfs(grid ,row+1 , col ,sum);
        dfs(grid ,row , col-1 ,sum);
        dfs(grid ,row , col+1 ,sum);
        grid[row][col]=temp; // backtracking from cell
        sum-=temp; // also removing the number of gold coin collected from that cell
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(); //number of row
        int m = grid[0].size(); // number of col
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum =0;
                dfs(grid , i, j , sum); //call dfs at every points in grid
                
            }
        }
        return ans;
    }
};