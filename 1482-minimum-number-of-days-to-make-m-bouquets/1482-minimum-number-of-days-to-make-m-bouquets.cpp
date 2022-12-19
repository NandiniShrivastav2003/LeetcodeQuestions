class Solution {
public:
    bool check(vector<int>arr,int mid, int m, int k){
        int res=0;
       int i=0;
        int count=0;
       for(int i=0;i<arr.size();i++){
           if(arr[i] <= mid){
               count++;
           }
           else{
               count=0;
           }
           if(count == k){
               res++;
               count=0;
           }
       }
        
//        while(i<bloomDay.size()){
//            bool f=false;
          
//            for(int j=i;j<i+k ;j++){
//                 if(i+k >= bloomDay.size()) {
//                if(res == m){
//                    return true;
//                }
//                return false;
//            }
//                if(bloomDay[j] > mid){
//                    i++;
//                    f=true;
//                    break;
//                }
//            }
           
//            if(!f){
//                i=i+k;
//                res++;
//            }
          
//        }
        
     
        return res>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size=bloomDay.size();
        // if(size < m*k){
        //     return -1;
        // }
        int l=INT_MAX;
        int h=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            l=min(l,bloomDay[i]);
            h=max(h,bloomDay[i]);
        }
        int ans=INT_MAX;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(check(bloomDay,mid,m,k)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans == INT_MAX ? -1:ans;
    }
};