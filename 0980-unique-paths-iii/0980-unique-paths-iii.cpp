class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int x,int y,int c,int empty){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() ||grid[x][y] == -1){
            return ;
        }
        if(grid[x][y] == 2 ){
             if(c == empty){
            ans++;
             }
            return ;
        }
        grid[x][y] = -1;
        dfs(grid,x,y-1,c+1,empty);
        dfs(grid,x,y+1,c+1,empty);
        dfs(grid,x-1,y,c+1,empty);
        dfs(grid,x+1,y,c+1,empty);
        grid[x][y] = 0;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x,start_y,end_x,end_y;
        int empty=1;
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1){
                    start_x=i;
                    start_y=j;
                }
                else if(grid[i][j] == 0){
                    empty++;
                }
                
            }
        }
     
        dfs(grid,start_x,start_y,c,empty);
        return ans;
    }
};