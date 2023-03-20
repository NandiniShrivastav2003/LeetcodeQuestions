class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n);
        //a boolean matrix to check if a edge is directly connected to another or not.
        int checked[n][n];
         memset(checked, 0, sizeof(checked));
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            indegree[a]++;
            indegree[b]++;
            checked[a][b]=1;
            checked[b][a]=1;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
        
                maxi=max(maxi,checked[i][j] == 1 ?indegree[i]+indegree[j]-1:indegree[i]+indegree[j]);
            }
        }
        return maxi;
    }
};