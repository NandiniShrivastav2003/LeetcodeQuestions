class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        int i=0;
        int j=nums.size()-1;
        int index=nums.size()-1;
        while(i <= j){
          if(abs(nums[i]) > abs(nums[j])){
              res[index]=nums[i]*nums[i];
              i++;
          }
            else{
                res[index]=nums[j]*nums[j];
                j--;
            }
            index--;

        }
        return res;
    }
};