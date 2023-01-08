class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
         vector<vector<int>> matrix(n, vector<int>(n,INT_MAX));
        for(auto t:edges){
            int i=t[0],j=t[1],val=t[2];
            matrix[i][j]=val;
            matrix[j][i]=val;
        }
         for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                
                matrix[i][i]=0;
    }   
        }
        for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            for(int k=0;k<n;k++){
	                if(matrix[j][i] != INT_MAX && matrix[i][k] != INT_MAX){
	                matrix[j][k]=min(matrix[j][k],matrix[j][i]+matrix[i][k]);
	                }
	            }
	        }
	    }
        int ans=INT_MAX;int temp=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            temp=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] <= d && i!=j){
                    temp++;
                }
               
            }
            mp[i]=temp;
           
        }
        int res;
       for(auto i:mp){
           if(i.second <= ans){
               res=i.first;
               ans=i.second;
           }
       }
        return res;
    }
};