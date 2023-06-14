
class Solution {
public:
    int find(int i,int parent[]){
        if(parent[i]  == -1){
            return i;
        }
        return find(parent[i],parent);
    }
    void dsu(int x,int y,int parent[],int rank[]){
        int a=find(x,parent);
        int b=find(y,parent);
      
            if(rank[a] > rank[b]){
                parent[a]=b;
            }
            else if(rank[a] < rank[b]){
                parent[b]=a;
            }
            else{
                parent[a]=b;
                rank[b]+=1;
            }
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int size=n*(n-1)/2;
        vector<vector<int>>adj;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<n;j++){
            int x1=points[i][0];
            int y1=points[i][1];
            int x2=points[j][0];
            int y2=points[j][1];
            int d=abs(x1-x2)+abs(y1-y2);
            adj.push_back({d,i,j});
        }
        }
        int parent[n];
        int rank[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
            sort(adj.begin(),adj.end());
           int ans=0;
        for(auto i:adj)
        {
            int w=i[0];
            int x=i[1];
            int y=i[2];
            if(find(x,parent) != find(y,parent)){
               ans+=w;
                dsu(x,y,parent,rank);
            }
;
        }
        
    return ans;
        
       
    }
};