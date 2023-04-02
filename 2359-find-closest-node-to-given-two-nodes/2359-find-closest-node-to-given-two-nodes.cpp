class Solution {
public:
void bfs(vector<int>adj[],int u,vector<int>&res){
    queue<int>q;
    q.push(u);
    set<int>vis;
    vis.insert(u);
    int dist=0;
    res[u]=0;
    while(!q.empty()){
        int n=q.size();
        ++dist;
        while(n--){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(vis.find(it) == vis.end()){
                vis.insert(it);
            res[it]=dist;
                q.push(it);
            }
        }
    }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>ans1(n,INT_MAX);
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edges[i] == -1){
                continue;
            }
            adj[i].push_back(edges[i]);
        }
        vector<int>ans2(n,INT_MAX);
        bfs(adj,node1,ans1);
        bfs(adj,node2,ans2);
        // for(int i:ans1){
        //     cout<<i<<" ";
        // }
     int  res=-1;
        int sum=INT_MAX;
        for(int i=0;i<n;i++){
            if(ans1[i] == INT_MAX || ans2[i] == INT_MAX){
                continue;
            }
            else if(sum > max(ans1[i],ans2[i])){
                sum=max(ans1[i],ans2[i]);
                res=i;
            }
            }
            
        return res;
    }
};