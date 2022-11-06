class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int j=1;
        for(int i=0;i<nums.size()&&j<nums.size();i+=2){
           while(i<nums.size()&&nums[i]%2 == 0){
               i+=2;
           } 
            while(j<nums.size()&&nums[j]%2 == 1){
                j+=2;
            }
            if(i<nums.size()){
                swap(nums[i],nums[j]);
            }
            j+=2;
        }
        return nums;
    }
};