class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        int ans=INT_MAX;
        int mini=-1;
        int x;
        for(int i=0;i<n;i++){
            int temp=(n-i-1);
            int a=pre[i]/(i+1);
            int b=(pre[n-1]-pre[i])/(temp == 0 ? 1:temp);
          x=abs(a-b);
            if( x < ans ){
                mini=i;
                ans=x;
            }
        }
        return mini;
    }
};