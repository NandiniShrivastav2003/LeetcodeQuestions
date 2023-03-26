class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      
       vector<pair<int,int>>adj[n];
       for(auto i:flights){
          adj[i[0]].push_back({i[1],i[2]});
       } 
    
        vector<int>dist(n,1e9);
        dist[src]=0;
          queue<vector<int>>q;
        //stops ,node,distance
       q.push({0,src,0});
      k=k+1;
       while(!q.empty()){
          vector<int>v=q.front();
           q.pop();
           if(v[0] > k){
               continue;
           }
           for(auto i:adj[v[1]]){
               int t=i.first;
               int d=i.second;
               if(dist[t]  > v[2] + d && v[0]+1 <= k){
                   dist[t] =v[2]+d;
                    q.push({v[0]+1,t,dist[t]});
               }
               
                   
                  
               
           }
       }
    return dist[dst] == 1e9 ? -1:dist[dst];
        
       
    }
};