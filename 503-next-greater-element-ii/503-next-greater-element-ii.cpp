class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>res(nums.size(),-1);
        stack<int>s;
        for(int i=0;i<nums.size()*2;i++){
            int num=nums[i%nums.size()];
            while(!s.empty() && nums[s.top()]<num){
                res[s.top()]=num;
                s.pop();
            }
            if(i<nums.size()){
                s.push(i);
            }
        }
        return res;
    }
};