class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        //maintain a prefix sum of no of ones and no of zeroes in two arrays.
        int n=nums.size();
        vector<int>zero(n+1,0);
        vector<int>ones(n+1,0);
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            zero[i+1]=(zero[i]);
        }
        else{
            zero[i+1]=(zero[i]+1);
        }
    }
        for(int i=n-1;i>=0;i--){
        if(nums[i] == 1){
            ones[i]=(1+ones[i+1]);
        }
        else{
            ones[i]=(ones[i+1]);
        }
    } 
        int ans=0;
        for(int i=0;i<=n;i++){
            ans=max(ans,ones[i]+zero[i]);
        }
        vector<int>res;
        for(int i=0;i<=n;i++){
            if(ones[i]+zero[i] == ans){
                res.push_back(i);
            }
        }
        return res;
        
    }
};