class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<int>res;
        int m=mat[0].size();
        for(int s=0;s<=(n+m-2);s++){
            for(int x=0;x<=s;x++){
                int i=x;
                int j=s-x;
                if(s % 2 == 0){
                    swap(i,j);
                }
                if(i >= n || j >= m){
                    continue;
                }
                res.push_back(mat[i][j]);
                
            }
        }
        return res;
    }
};