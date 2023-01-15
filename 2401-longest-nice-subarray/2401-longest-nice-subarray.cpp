class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0;
        //sor(^)
        int j=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            while((ans & nums[i]) != 0){
                ans=ans^(nums[j++]);
            }
            
                ans=ans | nums[i];
            
            res=max(i-j+1,res);
        }
        return res;
    }
};