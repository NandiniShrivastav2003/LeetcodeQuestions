class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();int n=mat[0].size();
       vector<vector<int>>vis(m,vector<int>(n,-1));
        
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int k=q.front().first;
            int l=q.front().second;
            q.pop();
          
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                if(k+dx[i]>= 0 && l+dy[i] >=0 && k+dx[i] <m && l+dy[i] <n  &&  vis[k+dx[i]][l+dy[i]] == -1){
                      vis[k][l]=1;
                    q.push({k+dx[i],l+dy[i]});
                   
                    if(ans[k+dx[i]][l+dy[i]] > ans[k][l]+1){
                    ans[k+dx[i]][l+dy[i]]=ans[k][l]+1;
                    }
                    
                }
                
            }
        }
        return ans;
    }
};