class Solution {
public:
     int ans=0;
   string removeABs(string s,int x){
        stack<char>st;
       string temp="";
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i] == 'b' && st.top() == 'a'){
                st.pop();
                ans+=x;
            }
            else{
                st.push(s[i]);
            }
        }
       while(!st.empty()){
           temp+=st.top();
           st.pop();
       }
       reverse(temp.begin(),temp.end());
        return temp;
    }
   string removeBA(string s,int x){
        stack<char>st;
       string temp="";
        for(int i=0;i<s.size();i++){
            if(!st.empty() && s[i] == 'a' && st.top() == 'b'){
                st.pop();
                ans+=x;
            }
            else{
                st.push(s[i]);
            }
        }
       while(!st.empty()){
           temp+=st.top();
           st.pop();
       }
       reverse(temp.begin(),temp.end());
        return temp;
    }
    int maximumGain(string s, int x, int y) {
       
        if(x > y){
           string temp= removeABs(s,x);
            string check=removeBA(temp,y);
        }
        else{
           string temp= removeBA(s,y);
           string check= removeABs(temp,x);
        }
        return ans;
    }
};