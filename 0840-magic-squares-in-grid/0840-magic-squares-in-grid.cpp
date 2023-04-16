class Solution {
public:
     
bool check(vector<vector<int>>&grid,int i,int j){
    set<int>orig({1,2,3,4,5,6,7,8,9});
    set<int>ch;
   int row1,row2,row3,col1,col2,col3,diag1,diag2;
    row1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
    row2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
    row3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
    col1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
     col2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
     col3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
    diag1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        diag2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
    ch.insert({row1,row2,row3,col1,col2,col3,diag1,diag2});
   
if(ch.size() == 1 && diag2 == 15){
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
               orig.erase(grid[r+i][c+j]);
            }
        }
        return orig.empty();
    }
    return false;

}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3){
            return 0;
        }
       
        
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i+2<m;i++){
         for(int j=0;j+2<n;j++){
        if(check(grid,i,j)){
            ans++;
            
        }
    
         }
        }
        return ans;
    }
};