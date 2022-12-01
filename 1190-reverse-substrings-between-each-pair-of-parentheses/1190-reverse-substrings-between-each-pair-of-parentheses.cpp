class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == ')'){
                string temp="";
                while(st.top() != '('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<temp.size();i++){
                    st.push(temp[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};