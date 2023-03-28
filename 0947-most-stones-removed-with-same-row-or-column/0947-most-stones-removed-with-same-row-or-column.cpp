class DisJointSet{
    public:
    vector<int>rank,size,parent;
    DisJointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
           
        }
        
    }
    int findUPar(int  node){
        if(node == parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void UnionBySize(int v1,int v2){
        int re1=findUPar(v1);
        int re2=findUPar(v2);
        if(re1 == re2){
            return ;
        }
        else if(size[re1] > size[re2]){
            parent[re2]=re1;
            size[re1]+=size[re2];
        }
        else{
            parent[re1]=re2;
            size[re2]+=size[re1];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      
       int r=INT_MIN,c=INT_MIN;
        int n=stones.size();
        for(int i=0;i<n;i++){
            r=max(r,stones[i][0]);
            c=max(c,stones[i][1]);
        }
          DisJointSet ds(r+c+1);
        unordered_map<int,int>stoneNodes;
        for(auto it:stones){
               
                  ds.UnionBySize(it[0],r+1+it[1]);
                stoneNodes[it[0]]=1;
                stoneNodes[r+1+it[1]]=1;
            }
        
        
        int ans=0;
        for(auto it:stoneNodes){
            if(ds. findUPar(it.first) == it.first){
                ans++;
            }
        }
        return n-ans;
        
    }
};