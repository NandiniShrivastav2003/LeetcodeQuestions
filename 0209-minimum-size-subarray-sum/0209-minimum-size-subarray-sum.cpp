class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int j=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(j<nums.size() && sum >= target){
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
            }
        }
        return ans == INT_MAX ?0 :ans;
    }
};