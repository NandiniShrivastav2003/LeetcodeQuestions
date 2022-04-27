// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	int getMin(vector<int>weight, vector<bool>visited)
{
    int m = INT_MAX;
    int min_index=-1;

    for (int i = 0; i < weight.size(); i++)
    {
        if (visited[i] == false && weight[i] < m)
        {
            
        m=weight[i];
        min_index = i;
            
        }
    }
    return min_index;
}
           
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
         vector<bool>visited(v,false);
    vector<int>parent(v);
    vector<int> weight(v);
    for(int i=0;i<v;i++){
        weight[i]=INT_MAX;
    }
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<v;i++){
        int ans=getMin(weight,visited);
        visited[ans]=true;
        for(auto it:adj[ans]){
          if(visited[it[0]] == false && it[1]<weight[it[0]]){
              weight[it[0]]=it[1];
          }
        }
}
    int sum=0;
    for(auto it:weight){
        sum+=(it);
    }
    return sum;
}
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends