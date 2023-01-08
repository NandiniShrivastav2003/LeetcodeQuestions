class DisjointSet{
public:
    vector<int>parent,usize;
    DisjointSet(int n){
             usize.resize(n+1);
        parent.resize(n+1);
        
        for(int i = 0 ; i<=n;i++)
        {
            usize[i] =1 ;
            parent[i] =i;
        }
   
    }
    int findUPar(int n){
         if(parent[n] == n)
        {
            return n;
        }
        else
        {
            return parent[n] = findUPar(parent[n]);
        }
    }
    void UnionBySize(int u , int v)
    {
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);
        
        if(ultp_u == ultp_v)
            return;
        else if(usize[ultp_u] > usize[ultp_v])
        {
            parent[ultp_v] = ultp_u;
            usize[ultp_u] += usize[ultp_v];
        }
        else
        {
            parent[ultp_u] = ultp_v;
            usize[ultp_v] += usize[ultp_u];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
/*using disjoint set(union find)
Note for me:
1) DSU extra edge of same component ko ignore karta hai
2) DSU minimum edge ka connected graph hota hai ( for visualization )
3) component of graph ki bat ho rahi think of DSU once
*/
        DisjointSet ds (n);
        int cntExtras=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtras++;
            }
            else{
                ds.UnionBySize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i) == i){
                cntC++;
            }
        }
        int ans=cntC-1;
        if(cntExtras >= ans){
            return ans;
        }
        return -1;
        
    }
};