class Solution {
public:
    bool makeStringsEqual(string s, string t) {
       int arr1[2],arr2[2];
       
        if( s == t){
            return true;
        }
        for(int i=0;i<s.size();i++){
            arr1[s[i]-'0']++;
        }
        for(int i=0;i<t.size();i++){
           arr2[t[i]-'0']++;
        }
        if( arr2[1] == 0 || arr1[1] == 0){
            return false;
        }
        return true;
    }
};