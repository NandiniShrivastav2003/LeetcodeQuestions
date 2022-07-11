class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=0;
        int curr;
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.empty() == false && heights[s.top()] >= heights[i]){
                int tmp=s.top();
                s.pop();
                curr=heights[tmp]*(s.empty()?i:i-s.top()-1);
                res=max(res,curr);
            }
            s.push(i);
        }
        while(s.empty() == false ){
                int tmp=s.top();
                s.pop();
                curr=heights[tmp]*(s.empty()?n:n-s.top()-1);
                res=max(res,curr);
            }
            
    return res;
    }
};