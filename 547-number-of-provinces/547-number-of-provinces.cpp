class Solution {
public:
    void dfs(int i,vector<vector<int>>&M,vector<bool>&visited){
        visited[i] =true;
        for(int j=0;j<visited.size();j++){
             if(!visited[j] && i!= j && M[i][j]){
                 dfs(j,M,visited);
             }
        }
       
    }
    int findCircleNum(vector<vector<int>>& M) {
         if (M.empty()) return 0;
        int n=M.size();
        int ans=0;
        vector<bool>visited(n,false);
        for(int i=0;i<visited.size();i++){
            if(visited[i] == false){
                ans++;
                dfs(i,M,visited);
                
            }
        }
        return ans;
    }
};