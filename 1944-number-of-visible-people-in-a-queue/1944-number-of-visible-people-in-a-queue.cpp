class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        vector<int>ans(heights.size(),0);
       for(int i=0;i<heights.size();i++){
           // if(!st.empty() && heights[st.top()] > heights[i]){
           //     ans[st.top()]++;
           // }
           while(!st.empty() && heights[st.top()] <= heights[i]){
               ans[st.top()]++;
               st.pop();
           }
           if(!st.empty()){
               ans[st.top()]++;
           }
           st.push(i);
       } 
        return ans;
    }
};