class Solution {
public:
    bool isPallindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i++] != s[j--]){
                return false;
            }
          
        }
          return true;
    }
    void func(int index,string s,vector<string>&path,vector<vector<string>>&res){
      
        if(index == s.size()){
            res.push_back(path);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPallindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                func(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>res;
       func(0,s,path,res);
        return res;
    }
};