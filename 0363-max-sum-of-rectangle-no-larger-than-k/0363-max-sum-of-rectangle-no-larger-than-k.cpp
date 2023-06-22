class Solution {
public:
     int f(vector<int> & v, int t ){
        int n=v.size(),ans=INT_MIN,sum=0;
        set<int>s;
        s.insert(0);
        for(int i=0;i<n;i++){
            sum+=v[i];
            auto it=s.lower_bound(sum-t);
            if(it!=s.end())ans=max(ans,sum-*it);
            s.insert(sum);
        }
        return ans;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& v, int t) {
        if(v.size()==0)return 0;
        int n=v.size(),m=v[0].size(),ans=INT_MIN;
        for(int j=0;j<m;j++){
            vector<int>a(n,0);
            for(int k=j;k<m;k++){
                for(int i=0;i<n;i++)a[i]+=v[i][k];
                ans=max(ans,f(a,t));
            }
        }
        return ans;
    }
};