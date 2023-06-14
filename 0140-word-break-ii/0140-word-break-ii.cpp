
class Solution {
public:
     vector<string>ans;
    set<int>vis;
    void helper(string s,int i,set<string>&st,vector<string>&a){
        if(i >= s.size()){
            string aa="";
            
            for(int i=0;i<a.size();i++){
            aa+=a[i];
                if(i != a.size()-1){
            aa+=" ";
                }
            }
        
            ans.push_back(aa);
            return ;
        }

        for(int curr=1;curr<=s.size();curr++){
            
            string v=s.substr(i,curr);
        
            if(st.find(v) == st.end()){
                continue;
            }
          
               a.push_back(v);
          helper(s,curr+i,st,a);
        a.pop_back();
            
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
         set<string>st;
        for(string i:wordDict){
            st.insert(i);
        }
        vector<string>a;
       
        helper(s,0,st,a);
        sort(ans.begin(),ans.end());
        ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
        
        return ans;
    }
};