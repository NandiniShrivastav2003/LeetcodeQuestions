class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int i=0;
        int j=0;
        int ans=INT_MIN;
        while(i<nums.size()){
            if(nums[i] == 0){
                zero++;
                
            }
            while(zero > 1 && j<nums.size()){
               if(nums[j] == 0){
                     zero--;
                 }
                j++;
             }
            
            if(zero == 1){
            ans=max(ans,i-j);
            }
            i++;
        }
        return ans == INT_MIN ? nums.size()-1 :ans;
    }
};