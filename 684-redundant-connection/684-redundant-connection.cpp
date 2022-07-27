class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>res;
        int n=edges.size();
        int parent[n+1];
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(auto v:edges){
           
            int n1=v[0];
            int n2=v[1];
           while(n1 != parent[n1]){
               n1=parent[n1];
           }
            while(n2 != parent[n2]){
               n2=parent[n2];
           }
            if(n1 == n2){
                res=v;
            }
            else{
                parent[n1]=n2;
            }
        }
        return res;
    }
};