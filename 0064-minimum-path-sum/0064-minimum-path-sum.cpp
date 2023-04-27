class Solution {
public:
    int minPathSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=1;i<n;i++){
mat[0][i]=mat[0][i]+mat[0][i-1];
}
for(int i=1;i<m;i++){
    mat[i][0]=mat[i][0]+mat[i-1][0];
}
for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
        mat[i][j]=min(mat[i-1][j],mat[i][j-1])+mat[i][j];
    }
}
return mat[m-1][n-1];
    }
};