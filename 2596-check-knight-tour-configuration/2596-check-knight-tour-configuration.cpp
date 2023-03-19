class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int last=grid.size()*grid.size()-1;
        int n=grid.size();
        int x=0;
        int y=0;
        int start=1;
        bool flag;
        while(true){
            
            int dx[8]={-2,-1,-2,-1,1,2,1,2};
            int dy[8]={-1,-2,1,2,-2,-1,2,1};
            flag=false;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n ){
                    if(grid[nx][ny] == start){
                        x=nx;
                        y=ny;
                        start++;
                        
                        flag=true;
                          if(grid[nx][ny] == last){
                      return true;
                      }
                        break;
                    }
                  
                }
            }
            
            if(flag == false){
                return false;
            }
        }
        return true;
    }
};