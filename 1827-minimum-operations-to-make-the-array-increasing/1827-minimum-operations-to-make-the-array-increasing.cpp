class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i]){
                continue;
            }
            else{
                int temp=nums[i-1]+1;
                ans+=(nums[i-1]+1-nums[i]);
                nums[i]=temp;
               
            }
        }
        return ans;
    }
};