class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=-1;
        int sum=0;
        int res=INT_MAX;
        
        while( i< nums.size()){
              if(sum < target){
                 ++j;
                if(j>=nums.size()){
                    break;
                }
                  sum+=nums[j];
               
            }
            else{
               res=min(res,(j-i+1));
                sum-=nums[i];
                i++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};