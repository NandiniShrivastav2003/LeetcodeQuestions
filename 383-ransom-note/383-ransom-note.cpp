class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>a;
        unordered_map<char,int>b;
        if(magazine.size()<ransomNote.size()){
            return false;
        }
        for(int i=0;i<magazine.size();i++){
            b[magazine[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            a[ransomNote[i]]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(b.find(ransomNote[i]) == b.end()){
                return false;
            }
            if(b.find(ransomNote[i]) != b.end() && b[ransomNote[i]] < a[ransomNote[i]]){
                return false;
            }
        }        
        return true;
        
    }
};