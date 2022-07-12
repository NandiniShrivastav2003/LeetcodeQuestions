class Solution {
public:
    int largestRectangleArea(int heights[],int n) {
        
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
    int maximalRectangle(vector<vector<char>>& matrix) {

        int res=0;
        int n=matrix[0].size();
        int m=matrix.size();
        int temp[n];
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(i == 0){
                       temp[j]=matrix[i][j]-'0';
                 }
                else  if(matrix[i][j] == '1'){
                       temp[j]=temp[j]+(matrix[i][j]-'0');
                 }
                 else{
                      temp[j]=0;
                 }
          
                 cout<<temp[j]<<" ";
        }
            cout<<endl;
            
            res=max(res, largestRectangleArea(temp,n));

        }
       return res;
    }
};