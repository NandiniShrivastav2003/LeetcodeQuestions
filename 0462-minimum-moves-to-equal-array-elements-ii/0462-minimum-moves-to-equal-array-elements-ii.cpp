class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int turns=0;
        int left=0;
        int temp=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            if(i == temp){
                continue;
            }
            else{
                turns+=abs(nums[i]-nums[temp]);
            }
        }
        return turns;
    }
};