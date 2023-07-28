class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
       int i=m-1;
        int j=n-1;
        int t1,t2;
        bool flag=false;
        while(i>=0 && j>=0){
            flag=false;
            if(i+1 >=0 && i+1 <m && mat[i+1][j] > mat[i][j]){
                t1=i+1;t2=j;
                flag=true;
            } 
            
             if(i-1 >=0 && i-1 <m && mat[i-1][j] > mat[i][j]){
                t1=i-1;t2=j;
                    flag=true;
            } 
             if(j+1 >=0 && j+1 <n && mat[i][j+1] > mat[i][j]){
                t1=i;t2=j+1;
                    flag=true;
            } 
             if(j-1 >=0 && j-1 <n && mat[i][j-1] > mat[i][j]){
                t1=i;t2=j-1;
                    flag=true;
            } 
            if(!flag){
                return {i,j};
            }
            i=t1;
            j=t2;
            
        }
        return {-1,-1};
    }
};