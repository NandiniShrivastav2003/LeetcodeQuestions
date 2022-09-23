class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int max=nums[i];
            int min=nums[i];
            for(int j=i;j<nums.size();j++){
                if(min > nums[j]){
                    min=nums[j];
                }
                if(max < nums[j]){
                    max=nums[j];
                }
                ans+=(max-min);
            }
            
        }
        return ans;
    }
};