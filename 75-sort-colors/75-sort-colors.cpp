class Solution {
public:
    void sortColors(vector<int>& nums) {
       int lo=0;
        int hi=nums.size()-1;
       int m=0;
        while(m<=hi){
            if(nums[m] == 0){
                swap(nums[lo++],nums[m++]);
            }
             else if(nums[m] == 2){
                swap(nums[hi--],nums[m]);
            }
            else{
                m++;
            }
        }
        
    }
};