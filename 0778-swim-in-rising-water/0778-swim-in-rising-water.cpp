class Solution {
public:
    //similar to path with minimum effort problem ,we have to make one chnage only in prev problem we maintain distance d = abs(mat[nx][ny]-mat[x][y]) here we have to find max value of a path from [0,0] to [m-1][n-1] which is minimum among all the paths so we will keep track of d=max(d,mat[nx][ny]);.
     typedef pair<int,pair<int, int>> pi;
    int swimInWater(vector<vector<int>>& heights) {
          int n=heights.size();
        int m=heights[0].size();
       vector<vector<int>>ans(n,vector<int>(m,1e6));
        ans[0][0]=heights[0][0];
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({ans[0][0],{0,0}});
        int dx[]={-1,0,0,1};
        int dy[]={0,-1,1,0};
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int d=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x == n-1 && y == m-1){
                return d;
            }
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                
                if(nx>=0 && ny>=0 && nx<n && ny<m ){
                    int temp=max(d,heights[nx][ny]);
                    if(ans[nx][ny] > temp){
                    ans[nx][ny]=temp;
                    pq.push({temp,make_pair(nx,ny)});
                }
                }
            }
        }
        return 0;
    }
};