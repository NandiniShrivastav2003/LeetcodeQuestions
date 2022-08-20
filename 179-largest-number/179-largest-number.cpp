class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
            if(to_string(nums[i])+to_string(nums[j]) >= to_string(nums[j])+to_string(nums[i])){
                
            }
            else{
            swap(nums[i],nums[j]);
            }
        }
        }
            for(int i=0;i<nums.size();i++){
                res+=to_string(nums[i]);
            }
        return res[0] == '0' ? "0":res;
    }
};