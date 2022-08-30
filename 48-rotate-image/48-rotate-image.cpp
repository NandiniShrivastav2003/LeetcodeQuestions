class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
                int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                temp=matrix[i][j];
                 matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
        }
}
        
int left=0;
        int right=n-1;
       while(left<right){
            for(int j=0;j<n;j++){
                swap(matrix[j][left],matrix[j][right]);
            }
        left++;
        right--;
        }
       
    }
};