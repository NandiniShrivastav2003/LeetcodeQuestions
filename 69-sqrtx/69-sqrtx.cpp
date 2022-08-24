class Solution {
public:
    int mySqrt(int x) {
        if( x == 1){
            return 1;
        }
         int low=1;
       int high=x/2;
       int mid;
        int ans=0;
       while(low<=high){
          mid = low + (high - low)/2;
           
            
           if(mid==x/mid){
               return mid;
           }
           else if(mid > x/mid){
               high=mid-1;
           }
           else{
               ans=max(ans,mid);
             low=mid+1;
           }
       }
        return ans;
    }
};