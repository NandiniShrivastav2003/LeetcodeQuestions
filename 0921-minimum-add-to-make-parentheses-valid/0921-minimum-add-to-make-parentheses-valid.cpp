class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top() == ')'){
                    st.push(s[i]);
                }
                else{
                st.pop();
                }
            }
        }
        return st.size();
    }
};