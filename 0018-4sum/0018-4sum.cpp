class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size() == 0){
            return ans;
        }
        if(nums.size() < 4){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                long  long sum=nums[i]+nums[j];
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    if(sum == (long long)target-(nums[left]+nums[right])){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    }
                    else if(sum > (long long)target-(nums[left]+nums[right])){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
     return ans;
    }
};