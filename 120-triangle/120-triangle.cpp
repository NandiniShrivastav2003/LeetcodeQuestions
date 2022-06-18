class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int>arr(triangle.back());
        for(int i=n-2;i>=0;i--){
            
            for(int j=0;j<=i;j++){
                arr[j]=min(arr[j],arr[j+1])+triangle[i][j];
        }
        }
        return arr[0];
    }
};