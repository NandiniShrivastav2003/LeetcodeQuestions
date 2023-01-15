class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
       int [][]ans=new int [n][n];
        int row1,col1,row2,col2;
        for(int i=0;i<queries.length;i++){
         
              row1=queries[i][0];
              col1=queries[i][1];
              row2=queries[i][2];
              col2=queries[i][3];
          
            for(int j=row1;j<=row2;j++ ){
                for(int k=col1;k<=col2;k++){
                     ans[j][k]=ans[j][k]+1;
                }
            }
        }
        return ans;
    }
}