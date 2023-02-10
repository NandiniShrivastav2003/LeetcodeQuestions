class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
    queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        if(q.size() == 0 || q.size() == n*n){
            return -1;
        }
        int ans=INT_MIN;
        int c=0;
        while(!q.empty()){
           
            int size=q.size();
            
            while(size--){
                 auto p=q.front();
            q.pop();
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nx=p.first+dx[i];
                int ny=p.second+dy[i];
                if(nx >= 0 && nx < n && ny>=0 && ny < n){
                    if(grid[nx][ny] == 0){
                        grid[nx][ny]=1;
                        q.push({nx,ny});
                    }
                ans=max(ans,grid[nx][ny]);
                }
            }
          
            }
            c++;

        }
        return c == 0 ? -1:c-1;
    }
};