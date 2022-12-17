class Solution {
public:
    bool check(vector<int>c,int mid,long long k){
        long long ans=0;
        if(mid == 0){
            return true;
        }
        for(int i=0;i<c.size();i++){
            if(c[i]>=mid){
                ans+=(c[i]/mid);
            }
            if(ans>=k){
                return true;
            }
         
        }
        return ans>=k;
    }
    int maximumCandies(vector<int>& c, long long k) {
        int lo=0;
        int hi=-1;
        for(int i=0;i<c.size();i++){
            hi=max(hi,c[i]);
        }
        int ans=0;
        while(lo<=hi){
      int mid=(lo+hi)/2;
            if(check(c,mid,k)){
                lo=mid+1;
                ans=max(ans,mid);
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};