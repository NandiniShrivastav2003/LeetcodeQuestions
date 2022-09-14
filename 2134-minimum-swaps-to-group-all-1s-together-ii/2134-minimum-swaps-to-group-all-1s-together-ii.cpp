class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
            if(nums[i] == 1){
            ones++;
            }
        }
        int k=ones;
      int no_zero=0;
        int ans=INT_MAX;
        for(int i=0;i<k;i++){
            if(nums[i] == 0){
               no_zero++;
            }
            
        }
    
    ans=min(ans,no_zero);
        
        for(int i=k;i<nums.size();i++){
            if(nums[i] == 0){
                no_zero++;
            }
            if(nums[i-k] == 0){
                no_zero--;
            }
           ans=min(ans,no_zero);
        }
        return ans;
    }
};