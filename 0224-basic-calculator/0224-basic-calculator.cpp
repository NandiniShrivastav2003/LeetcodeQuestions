class Solution {
public:
    int calculate(string s) {
        int res=0;
        int sign=1;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if( isdigit(s[i])){
                long sum=s[i]-'0';
                while(i+1 < s.size() && isdigit(s[i+1])){
                    sum=sum*10+s[i+1]-'0';
                    i++;
                }
                res+=sum*sign;
            }
            else if(s[i] == '+'){
                sign=1;
            }
            else if(s[i] == '-'){
                sign=-1;
            }
            else if(s[i] == '('){
               
                st.push(res);
                 st.push(sign);
                res=0;sign=1;
            }
            else if(s[i] == ')'){
                res=res*st.top();
                st.pop();
                res+=st.top();
                st.pop();
            }
            
        }
        return res;
    }
};