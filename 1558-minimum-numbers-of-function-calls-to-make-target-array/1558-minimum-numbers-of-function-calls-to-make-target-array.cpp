class Solution {
public:
    bool check(vector<int>nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int c=0;
       
            while(true){
               
            for(int i=0;i<nums.size();i++){
            if(nums[i] % 2 == 1){
                nums[i]=nums[i]-1;
                c++;
            }
            }
                if(check(nums)){
                    return c;
                }
                for(int i=0;i<nums.size();i++){
                    if(nums[i] != 0){
                    nums[i]=nums[i]/2;
                   
                    }
                }
                c++;
                
                
        }
        return c;
    }
};