class Solution {
public:
    int kadane(vector<int>& A){
        int currentSum = A[0];
        int maxSum = A[0];
        for(int i=1;i<A.size();i++){
            if(currentSum < 0)
                currentSum = 0;
            currentSum = A[i] + currentSum;
            maxSum =max(maxSum,currentSum);
        }
        return maxSum;
    }
//     int kadane(vector<int>&nums){

//         int ans=0;
//         int res=nums[0];
//         for(int i=0;i<nums.size();i++){
//             ans+=nums[i];
           
//             if(ans<0){
//                 ans=0;
//             }
//               res=max(res,ans);
            
//         }
//         return res;
//     }
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=0;
        int sum2=kadane(nums);
       
        for(int i=0;i<nums.size();i++){
            ans+=nums[i];
            nums[i]=-nums[i];
        }
        if(sum2 < 0){
            return sum2;
        }
       int sum= kadane(nums);
        int sum3=(ans-(-sum));
        return max(sum3,sum2);
    }
};