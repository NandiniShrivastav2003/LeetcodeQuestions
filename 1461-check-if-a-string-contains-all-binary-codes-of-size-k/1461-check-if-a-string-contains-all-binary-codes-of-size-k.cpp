class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        for(int i=0;i+k<=s.size();i++){
            st.insert(s.substr(i,k));
            //cout<<s.substr(i,k)<<endl;
        }
        return st.size() >= pow(2,k); 
        
    }
};