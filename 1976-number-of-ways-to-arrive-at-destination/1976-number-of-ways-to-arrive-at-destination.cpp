class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
         priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, 
         greater<pair<long long, long long>>> pq;
         
         vector<long long> distance(n,1e18);
         
         vector<long long> ways(n,0);
         pq.push({0,0});
         
         distance[0]=0;
         ways[0]=1;
         
         int mod=(1e9+7);
         while(!pq.empty()){
             long long dis=pq.top().first;
             long long node=pq.top().second; 
             pq.pop();
             
             for(auto it: adj[node])
             {
                 long long adjNode=it.first;
                 
                 long long edgewt = it.second;
                 
                 if(dis+edgewt<distance[adjNode])
                 {
                     distance[adjNode]=dis+edgewt;
                     
                     pq.push({dis+edgewt,adjNode});
                     
                     ways[adjNode]=ways[node];
                     
                 } else if(dis+edgewt == distance[adjNode])
                 {
                     ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                 }
                     
                 }
             }
         return ways[n-1]%mod;
    }
};