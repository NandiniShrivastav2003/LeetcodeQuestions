class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int n=0;
  for(int i=0;i<nums.size();i++){
      if(nums[i] == 0){
          n++;
      }
      else{
          n=0;
      }
      ans+=n;
  }     
        return ans;
    }
};