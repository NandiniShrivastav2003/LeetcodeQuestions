class Solution {
public:
    //we store indices of index and at the end stack only contain index where-
    //Scan the string from beginning to end.
// If current character is '(',
// push its index to the stack. If current character is ')' and the
// character at the index of the top of stack is '(', we just find a
// matching pair so pop from the stack. Otherwise, we push the index of
// ')' to the stack.
// After the scan is done, the stack will only
// contain the indices of characters which cannot be matched. Then
// let's use the opposite side - substring between adjacent indices
// should be valid parentheses.
// If the stack is empty, the whole input
// string is valid. Otherwise, we can scan the stack to get longest
// valid substring as described in step 3.
    int longestValidParentheses(string s) {
        stack<int>st;
int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    if(s[st.top()] == '('){
                        st.pop();
                    }
                    else{
                      st.push(i);  
                    }
                }
                else{
                    st.push(i);
                }
            }
        }
        //if whole string is valid then ans --lenth of string
        if(st.empty()){
            return s.size();
        }
            int n=s.size();
            int b;
        int a=n;
            while(!st.empty()){
                b=st.top();st.pop();
                ans=max(ans,a-b-1);
                a=b;
            }
        //this line for handling edge cases-"())"  our ans should be max(a=2 ,ans=0)
        ans=max(ans,a);
        return ans;
    }
};