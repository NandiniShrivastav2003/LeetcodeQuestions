class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algo
        int res=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size() ;i++) {
        sum+=nums [i];
            res=max(res, sum) ;
            if(sum<0) {
                sum=0;
            }
            
            }
        return res;
    }
    int maxAbsoluteSum(vector<int>& nums) {
       int sum1= maxSubArray(nums);
        for(int i=0;i<nums.size();i++){
            nums[i]=-nums[i];
        }
        int sum2=maxSubArray(nums);
        return max(sum1,sum2);
    }
};