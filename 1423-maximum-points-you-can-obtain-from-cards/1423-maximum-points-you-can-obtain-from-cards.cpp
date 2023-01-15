class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int ans=0,res=INT_MAX;
        int size=arr.size()-k;
        for(int i=0;i<size;i++){
            ans+=arr[i];
        }
        res=min(res,ans);
        for(int i=size;i<arr.size();i++){
            ans-=arr[i-size];
            ans+=arr[i];
            res=min(ans,res);
        }
       
    return sum-res;
        }
};