class Solution {
public:
 
    void subset(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int i){
       if(i > nums.size()){
           return ;
       }
       if(i == nums.size()){
           ans.push_back(temp);
           return ;
       }
       subset(nums,temp,ans,i+1);
       temp.push_back(nums[i]);
       subset(nums,temp,ans,i+1);
       temp.pop_back();
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
    vector<int>temp;
        subset(nums,temp,ans,0);
        sort(ans.begin(),ans.end());
        ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};