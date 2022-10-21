class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    void combsum(vector<int>nums,int k,int n,int sum,int idx){
        if(sum == n && temp.size() == k){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
           // sum+=nums[i];
            combsum(nums,k,n,sum+nums[i],idx+1);
            temp.pop_back();
            idx=idx+1;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        combsum(nums,k,n,0,0);
        return ans;
    }
};