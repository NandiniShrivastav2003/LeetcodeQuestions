class Solution {
public:
    int sum(vector<int>q){
        int ans=0;
        int fin=0;
        for(int i=0;i<q.size();i++){
            fin=max(fin,q[i]);
        }
        return fin;
    }
    int check(vector<int>q,int mid,int n){
        int ans=0;
        for(int i=0;i<q.size();i++){
            ans+=q[i]/mid;
            if(q[i]%mid != 0){
                ans++;
            }
            
        }
        return ans;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo=1;
        int res=INT_MAX;
        int hi=sum(quantities);
        while(lo<=hi){
            int mid=(lo+hi)/2;
            //cout<<mid<<endl;
            if(check(quantities,mid,n) == n){
                res=min(res,mid);
                hi=mid-1;
            }
            else if(check(quantities,mid,n) > n){
               lo=mid+1; 
            }
            else{
                hi=mid-1;
            }
        }
        return lo;
    }
};