class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int res=0;
        int count;
        for (int i=0;i<s.length() ;i++) {
           // res=max(res,count);
            //st.clear();
            count =0;
            for(int j=i;j<s.length() ;j++) {
                if(st.find(s[j]) != st.end()) {
                    break;
                }
                   else{
                       st.insert(s[j]);
                       count++;}
                }
                  res=max(res, count) ;
                   st. clear() ;
            
                   
                   }
                   return res;
    }
                   
};