class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int water=0;
    int i=0;
        while(i<height.size()){
            if(st.empty() || (height[i] <= height[st.top()])){
                st.push(i);
                i++;
            }
            else{
                int pre=st.top();
                st.pop();
                if(!st.empty()){
                int minheight=min(height[i],height[st.top()]);
                water+=(minheight-height[pre])*(i-st.top()-1);
                   }
            }
        }
        return water;
    }
};