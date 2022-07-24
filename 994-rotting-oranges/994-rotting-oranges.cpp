class Solution {
public:
    int ans=-1;
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>>q){
       
      int dx[4]={0,-1,1,0};
        int dy[4]={-1,0,0,1};
        while(!q.empty()){
            ans++;
              int size=q.size();
        while(size--){
            pair<int,int>s=q.front();
            q.pop();
            for(int i=0;i<4;i++){
           int nx=s.first+dx[i];
                int ny=s.second+dy[i];
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny] == 1){
            q.push({nx,ny});
            grid[nx][ny]=2;
        }
            }
        }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {

        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                  q.push({i,j});
                }
            }
        }
          bfs(grid,q);
         for(int i=0;i<n;i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
         }
        return ans == -1 ? 0:ans;
    }
};