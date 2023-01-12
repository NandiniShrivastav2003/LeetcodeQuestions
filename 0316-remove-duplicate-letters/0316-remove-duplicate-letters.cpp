class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        map<char,int>vis;
        stack<char>st;
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(vis.find(s[i]) != vis.end()){
                mp[s[i]]--;
                continue;
            }
            if(st.empty()){
                st.push(s[i]);
                 
            }
            else if(!st.empty() && st.top()<s[i]){
                st.push(s[i]);
              
            }
            else{
                while(!st.empty() && st.top()>s[i] && mp[st.top()] > 0){
                vis.erase(st.top());
                st.pop();
                   
                }
                st.push(s[i]);
                
            }
             mp[s[i]]--;
            vis[s[i]]++;
        }
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};