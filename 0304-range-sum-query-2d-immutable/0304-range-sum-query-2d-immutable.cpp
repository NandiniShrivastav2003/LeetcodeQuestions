class NumMatrix {
public:
    //using 2d prefix sum
     vector<vector<int>>prefix;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
   prefix=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                prefix[i][j]=matrix[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
        
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<prefix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int a, int b, int c, int d) {
     // cout<<prefix[c+1][d+1]<<" "<<prefix[a][d+1]<<" "<<prefix[c+1][b]<<" "<<prefix[a][b]<<endl;
        return prefix[c+1][d+1]-prefix[a][d+1]-prefix[c+1][b]+prefix[a][b];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */