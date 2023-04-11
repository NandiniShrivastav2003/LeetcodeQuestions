class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;
        int ans=0;
        int cnt=0;
        for(int i=nums.size()-1;i>=0;i--){
            cnt=0;
            while(!st.empty() && nums[i] > st.top().first){
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            ans=max(ans,cnt);
            st.push({nums[i],cnt});
        }
     return ans;
    }
};