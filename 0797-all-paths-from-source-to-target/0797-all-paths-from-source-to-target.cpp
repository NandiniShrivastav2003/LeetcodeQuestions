class Solution {
public:
    void dfs( vector<int>&temp,vector<vector<int>>&ans,vector<vector<int>>& graph,int curr,int dest){
        if(curr == dest){
            ans.push_back(temp);
            return ;
        }
        for(auto x:graph[curr]){
            temp.push_back(x);
            dfs(temp,ans,graph,x,dest);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>adj[graph.size()];
        // for(int i=0;i<graph.size();i++){
        //     for(int j=0)
        //     adj[i].push_back()
        // }
        int src=0;
        int dest=graph.size()-1;
        vector<int>temp;
        temp.push_back(0);
        vector<vector<int>>ans;
        dfs(temp,ans,graph,0,dest);
        return ans;
    }
};