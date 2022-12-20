class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>ans;
        while(i<n){
            int correctidx=nums[i]-1;
            if(nums[i] != nums[correctidx]){
                swap(nums[i],nums[correctidx]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                ans.push_back(i+1);
            }
        }
        return ans;  
    }
};