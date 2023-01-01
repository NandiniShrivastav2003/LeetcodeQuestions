class Solution {
public:
    bool isomorphic(string s,vector<string>t){
        if(s.size () != t.size()){
            return false;
        }
       set<char>a;
        unordered_map<string,char>b;
        for(int i=0;i<s.size();i++){
            if(a.find(s[i]) == a.end() && b.find(t[i]) == b.end()){
                a.insert(s[i]);
                b[t[i]]=s[i];
           }
            else if( b[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
    bool wordPattern(string pattern, string s) {
         istringstream ss(s);
 vector<string>res;
         string word;
         while (ss >> word)
    {
       res.push_back(word);
    }
        return isomorphic(pattern,res);
    }
};