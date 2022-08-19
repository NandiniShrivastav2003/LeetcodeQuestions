class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int res=1;
        int ans=1;
        int temp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] != temp){
            if(nums[i] == temp+1){
                temp=nums[i];
                ans++;
            }
            else{
                temp=nums[i];
                res=max(res,ans);
                ans=1;
            }
        }
        }
        res=max(res,ans);
        
        return res;
    }
};