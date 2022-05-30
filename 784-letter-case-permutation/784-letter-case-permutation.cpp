class Solution {
public:
    void solve(string s,string t,vector<string>&res,int i){
        if(i == s.size()){
            res.push_back(t);
            return ;
        }
        
        if(isalpha(s[i])){
            string out1="";
             string out2="";
          
                out1=toupper(s[i]);
                out2=tolower(s[i]);
        solve(s,t+out1,res,i+1);
           solve(s,t+out2,res,i+1);
        

        }
     else{
         solve(s,t+s[i],res,i+1);
     }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        solve(s,"",res,0);
        return res;
    }
};