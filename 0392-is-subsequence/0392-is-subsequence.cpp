class Solution {
public:
    int temp=0;
    bool check(string s,string t,int i){
        if(temp == s.size()){
            return true;
            
        }
        if(i >= t.size()){
            return false;
        }
        
        if(s[temp] == t[i]){
            
            temp=temp+1;
        }
        return check(s,t,i+1);
    }
    bool isSubsequence(string s, string t) {
        return check(s,t,0);
    }
};