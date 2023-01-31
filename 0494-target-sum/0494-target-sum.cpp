class Solution {
public:
    int ans=0;
    void helper(int i , int target , vector<int>&arr ,int sum)
{
        if( i == arr.size()){
            if(sum == target){
            ans++;
            }
        }
    // if(sum > target || i>=arr.size()){
    //     return ;
    // }
        else{
        
        helper(i+1,target,arr,sum-arr[i]);
        helper(i+1,target,arr,sum+arr[i]);
        }
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        //vector<vector<int>>dp(n,vector<int>(target+1,-1));
        helper(0,target,nums,0);
        return ans;
    }
};