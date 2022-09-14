class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int si=0;
        int ei=0;
        int p=1;
        while(ei<nums.size()){
            //grow the window
            p*=nums[ei];
            
            
            //shrink the window
            while(p>=k && si<=ei){
                p=p/nums[si];
                si++;
                
            }
            ans+=(ei-si+1);
            //calculate answer
            ei++;
        }
        return ans;
    }
};