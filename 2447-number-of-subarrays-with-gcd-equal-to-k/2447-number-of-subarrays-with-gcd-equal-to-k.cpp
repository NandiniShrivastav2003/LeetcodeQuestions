class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int gcd1=nums[i];
            if(gcd1 == k){
                res++;
            }
            for(int j=i+1;j<n;j++){
                gcd1=gcd(gcd1,nums[j]);
                if(gcd1 == k){
                    res++;
                }
            }
        }
        return res;
    }
};