class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>row;
        vector<int>col;
        int n=grid.size();
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[i][j]);
            }
            row.push_back(maxi);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<n;j++){
                maxi=max(maxi,grid[j][i]);
            }
            col.push_back(maxi);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int a=row[i];
                int b=col[j];
                if( grid[i][j] == a || grid[i][j] == b){
                    continue;
                }
                ans+=min(a,b)-grid[i][j];
            }
        }
    return ans;
    }
};