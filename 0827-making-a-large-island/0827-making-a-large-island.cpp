class DisjointSet {
public: 
vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
    private:
    //intution-we convert every cell to its corresponding value from 0 to n*n-1.
    //then we will make union by size of all the components.
    bool isverify(int adjr,int adjc,int n)
    {
        return adjr>=0&&adjr<n&&adjc>=0&&adjc<n;
    }
  public:
    int largestIsland(vector<vector<int>>& grid)
    {
       int n=grid.size();
        DisjointSet ds(n*n);
       //step1
       for(int row=0;row<n;row++)
       {
           for(int col=0;col<n;col++)
           {
               if(grid[row][col]==0)
               {
                   continue;
               }
               else
               {
                   int delrow[]={-1,0,1,0};
                   int delcol[]={0,-1,0,1};
                   for(int i=0;i<4;i++)
                   {
                       int adjr=row+delrow[i];
                       int adjc=col+delcol[i];
                       if(isverify(adjr,adjc,n)&&grid[adjr][adjc]==1)
                       {
                           int nrow=row*n+col;
                           int ncol=adjr*n+adjc;
                           ds.unionBySize(nrow,ncol);
                       }
                   }
               }
           }
       }
       //step2-we try every possibility of making 0 to 1 and then taking max of( size of all of its four adjacents.)
       int mx=0;
       for(int row=0;row<n;row++)
       {
           for(int col=0;col<n;col++)
           {
                if(grid[row][col]==1)
               {
                   continue;
               }
               else
               {
                   int delrow[]={-1,0,1,0};
                   int delcol[]={0,-1,0,1};
                   
                    set<int>sa;
                   for(int i=0;i<4;i++)
                   {
                       int adjr=row+delrow[i];
                       int adjc=col+delcol[i];
                       if(isverify(adjr,adjc,n))
                       {
                           if(grid[adjr][adjc]==1)
                           {
                               sa.insert(ds.findUPar(adjr*n+adjc));
                           }
                       }
                  }
                   int size1=0;
                  for(auto it:sa)
                  {
                     size1+=ds.size[it]; 
                  }
                  mx=max(size1+1,mx);
                }
            }
           //this condition is for handling cases where there are no zeroes  like in test case-3 in this case we return n=2 (n*n-1) size[3]=4;
       mx=max(mx,ds.size[ds.findUPar(n*n-1)]);
           
        }
        
        return mx;
   }
};