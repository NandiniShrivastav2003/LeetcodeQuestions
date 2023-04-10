class Solution {
public:
    char check(vector<int>&alpha){
       
        for(int i=0;i<26;i++){
            if(alpha[i] > 0){
                return char(i+'a');
            }
        }
        return 'a';
    }
    string robotWithString(string s) {
        vector<int>alpha(26,0);
        for(char c:s){
            alpha[c-'a']++;
        }
      
        stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
        
               st.push(s[i]);
             alpha[s[i]-'a']--;
           while(!st.empty() && st.top() <= check(alpha)){
             
                ans+=st.top();
              st.pop();
           }
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};