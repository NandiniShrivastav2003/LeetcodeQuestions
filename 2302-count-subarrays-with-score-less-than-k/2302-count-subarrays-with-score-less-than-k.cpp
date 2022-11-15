class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int si=0;
        int ei=0;
        long long ans=0;
        long long  sum=0;
        while(ei < nums.size()){
            sum+=nums[ei];
            while((ei-si+1)*sum >= k){
                    sum-=nums[si];
                    si++;
                    
                }
            ans+=(ei-si+1);
            ei++;
            
        }
        return ans;
    }
};