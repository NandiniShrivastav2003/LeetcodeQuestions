class Solution {
public:
    //using cyclic sort and pigeonhole principle
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long correctidx=(long long)nums[i]-1;
            while(correctidx>=0 && correctidx<n && nums[i] != nums[correctidx]){
                swap(nums[i],nums[correctidx]);
                correctidx=(long long)nums[i]-1;
            }
        }
            for(int i=0;i<n;i++ ){
                if(nums[i] != i+1){
                    return i+1;
                }
            }
        return n+1;
        
    }
};