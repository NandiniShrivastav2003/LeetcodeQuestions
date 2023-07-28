class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int a=(i+1 >=0 && i+1 <m)?(mat[i][j] > mat[i+1][j]):1;
                  int b=(i-1 >=0 && i-1 <m)?(mat[i][j] > mat[i-1][j]):1;
                  int c=(j+1 >=0 && j+1 <n)?(mat[i][j] > mat[i][j+1]):1;
                  int d=(j-1 >=0 && j-1 <n)?(mat[i][j] > mat[i][j-1]):1;
            if(a&&b&&c&&d){
                return {i,j};
            }
            }
        }
        return {-1,-1};
    }
};