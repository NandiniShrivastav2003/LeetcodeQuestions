class Solution {
public:
//    bool dfs(vector<vector<int>>graph,int u,vector<int>&color,int parent){
//        if(parent == -1){
//            color[u]=1;
//        }
//        else{
//             color[u]=~color[parent];
//        }
           
       
       
//         for(auto v:graph[u]){
//             if(color[v] == -1){
              
//                 if(!dfs(graph,v,color,u)){
//                     return false;
//                 }
//             }
      
//             else if(color[v] == color[u]){
               
//                 return false;
//                 }
            
//         }
//         return true;
//     }
    bool dfs(vector<vector<int>>adj,int u,vector<int>&col,int parent){
         if(parent == -1){
             col[u]=1;
         }
         else{
             col[u]=~col[parent];
         }
         for(auto v:adj[u]){
             if(col[v] == -1){
                 if(!dfs(adj,v,col,u)){
                     return false;
                 }
             }
             else if(col[v] == col[u]){
                 return false;
             }
         }
return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++){
           if(color[i] == -1){
               if(!dfs(graph,i,color,-1)){
                   return false;
               }
           }
        }
        return true;
    }
};