class Solution {
public:
    int numJewelsInStones(string j, string s) {
       unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=0;
        for(int i=0;i<j.size();i++){
            ans+=mp[j[i]];
        }
        return ans;
    }
};