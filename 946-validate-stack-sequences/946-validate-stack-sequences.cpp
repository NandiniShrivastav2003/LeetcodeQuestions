class Solution {
public:
    bool validateStackSequences(vector<int>& A, vector<int>& B) {
        stack<int>s;
        int n=A.size();
        int i=0;
        int j=0;
        while(i<n && j<n){
             if(!s.empty() && s.top() == B[j]){
                s.pop();
                j++;
             }
            else if(A[i] == B[j]){
                j++;
                i++;
                
            }
            else{
                s.push(A[i]);
                i++;
            }
            
        }
        while(!s.empty() && j<n){
            if(s.top () != B[j]){
                break;
              
            }
            s.pop();
              j++;
        }
        return s.empty();
    }
};