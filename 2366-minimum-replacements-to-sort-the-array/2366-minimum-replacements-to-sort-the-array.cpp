class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int right=nums[nums.size()-1];
        long long ans=0;
     for(int i=nums.size()-2;i>=0;i--){
         if(right>= nums[i]){
             right=nums[i];
         }
         else{
            int temp=(nums[i]-1)/right+1;
             ans+=(temp-1);
             right=nums[i]/temp;
         }
     }   
        return ans;
    }
};