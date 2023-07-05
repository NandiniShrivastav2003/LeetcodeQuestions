class Solution {
public:
    bool check(vector<int>&arr,int mid,int k){
    int ans=1;
    int dis=arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-dis >= mid){
            ans++;
            dis=arr[i];
        }
    }
    return ans >= k;
    
}
    int maximumTastiness(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
          int lo=1;
         int hi=arr[n-1];
         int ans=0;
         while(lo<=hi){
             int mid=(lo+hi)/2;
             if(check(arr,mid,k)){
                 ans=mid;
                 lo=mid+1;
                 
             }
             else{
                 hi=mid-1;
             }
         }
         return ans;
    }
};