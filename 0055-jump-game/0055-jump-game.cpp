class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJums=0;
        for(int i=nums.size()-2;i>=0;i--){
            minJums++;
            if(nums[i] >= minJums){
                minJums=0;
            }
        }
        if(minJums == 0){
            return true;
        }
        return false;
    }
};