class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        //[2,6,7,8,16,21] start with left =0 , i=2 and right = i-1 
        //and like 3 sum problem check if sum of two sides                           //nums[left]+nums[right] >nums[i] 
        //increment ans 
        for(int i=2;i<nums.size();i++){
            int left=0;int right=i-1;
            while(left<right){
                if(nums[left]+nums[right]  > nums[i]){
                    ans+=(right-left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return ans;
    }
};