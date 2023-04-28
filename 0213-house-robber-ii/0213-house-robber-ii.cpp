class Solution {
public:
    int houserob(vector<int>&arr,int dp[]){
for(int i=0;i<arr.size();i++){
    dp[i]=max((i-1 < 0?0:dp[i-1]),arr[i]+((i-2)<0 ?0:dp[i-2]));
}
return dp[arr.size()-1];
}
    int rob(vector<int>&arr) {
        if(arr.size() == 1){
            return arr[0];
        }
        int n=arr.size();
        vector<int>res1;
vector<int>res2;
for(int i=0;i<n-1;i++){
   res1.push_back(arr[i]);
}
for(int i=1;i<n;i++){
   res2.push_back(arr[i]);
}
int dp1[n-1];
int dp2[n-1];
       int a=houserob(res1,dp1);
     //   cout<<a<<endl;
        int b=houserob(res2,dp2);
       //cout<<b<<endl;
return max(a,b);
        return 0;
    }
};