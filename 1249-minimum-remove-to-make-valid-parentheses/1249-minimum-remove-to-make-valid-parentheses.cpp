class Solution {
public:
    string minRemoveToMakeValid(string s) {
     stack<pair<char,int>>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(st.empty() && s[i] == ')'){
                st.push({')',i});
                continue;
            }
            if(s[i] == '('){
               st.push({'(',i}); 
            }
            else if(s[i] == ')'){
                if(st.top().first == '('){
                st.pop();
                }
                else{
                    st.push({')',i});
                }
            }
           }
       for(int i=s.size()-1;i>=0;i--){
           if(!st.empty() && i == st.top().second){
               st.pop();
               continue;
           }
           else{
               ans+=s[i];
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};