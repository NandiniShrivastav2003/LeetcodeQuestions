class Solution {
public:

    bool closeStrings(string word1, string word2) {
        map<char,int>mp1;
        set<char>s1;set<char>s2;
        map<char,int>mp2;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
            s1.insert(word1[i]);
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
             s2.insert(word2[i]);
        }
        vector<int>v1;
        vector<int>v2;
        for(auto i:mp1){
            v1.push_back(i.second);
        }
        for(auto i:mp2){
            v2.push_back(i.second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1 == v2 && s1 == s2;
    }
};