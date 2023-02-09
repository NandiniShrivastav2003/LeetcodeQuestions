class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      vector<int>mini(nums.size());
        mini[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            mini[i]=min(nums[i],mini[i-1]);
        }
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            while(!st.empty() && st.top()-1>=0 && st.size()>=1 && mini[st.top()-1] < nums[i]){
                return true;
            }
            st.push(i);
        }
        return false;
    }
};