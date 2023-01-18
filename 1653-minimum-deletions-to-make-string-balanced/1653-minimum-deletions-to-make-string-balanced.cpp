class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
          
                if(!st.empty() && st.top() < s[i]){
                  
                    ans++;
                    st.pop();
                }
            
        else{
            st.push(s[i]);
        }
        }
        return ans;
    }
};