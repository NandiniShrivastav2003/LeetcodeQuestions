class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        
         int diff=nums[1]-nums[0];
        int count=0;
        int ans=0;
        for(int i=2;i<nums.size();i++){
           if(nums[i]-nums[i-1] == diff){
               count++;
           }
            else{
                diff=nums[i]-nums[i-1];
                count=0;
            }
            ans+=count;
        }
        return ans;
    }
};