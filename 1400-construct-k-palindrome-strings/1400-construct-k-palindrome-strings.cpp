class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k){
            return false;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int count=0;
        for(auto i:mp){
            if(i.second % 2 == 1){
                count++;
            }
        }
     if(count > k){
         return false;
     }   
        return true;
    }
};