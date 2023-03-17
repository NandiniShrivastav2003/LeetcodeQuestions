//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
void dfs(vector<int>adj[],bool vis[],int u, vector<vector<int>>&ans,int vertex){
    vis[u]=true;
    ans[vertex][u]=1;
    for(int v:adj[u]){
        if(!vis[v]){
        dfs(adj,vis,v,ans,vertex);
    }
    }
    
         
}
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<int>adj[N];
        vector<vector<int>>ans(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i != j && graph[i][j]){
                adj[i].push_back(j);
                }
            }
        }
        for(int i=0;i<N;i++){
            bool vis[N]={false};
            ans[i][i]=1;
            dfs(adj,vis,i,ans,i);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends