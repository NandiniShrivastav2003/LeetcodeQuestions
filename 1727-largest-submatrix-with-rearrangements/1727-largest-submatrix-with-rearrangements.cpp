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
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
      vector<int>ans;
        int res=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
              if(matrix[i][j] == 0){
                  matrix[i][j]=0;
              }
                else{
                    matrix[i][j]=matrix[i-1][j]+1;
                }
               
            }
        }
            for(vector<int>v:matrix){
                sort(v.begin(),v.end());
            res=max(res,largestRectangleArea(v));
            }
        
       
        
        return res;
    }
};