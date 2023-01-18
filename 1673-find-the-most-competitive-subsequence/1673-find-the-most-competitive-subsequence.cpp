class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ans;
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(st.empty() || st.top() <= nums[i]){
                st.push(nums[i]);
                
               
            }
            else if( !st.empty() && st.top() > nums[i]){
                while(!st.empty() && st.top() > nums[i] && st.size() + (n -i) > k) {
                    st.pop();
                }
                st.push(nums[i]);
            }
        }
    while(st.size() > k){
        st.pop();
    }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};