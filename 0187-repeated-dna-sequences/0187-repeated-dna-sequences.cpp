class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     unordered_map<string,int>mp;
        vector<string>ans;
        if(s.size()<10){
            return ans;
        }
        for(int i=0;i+10<=s.size();i++){
            mp[s.substr(i,10)]++;
        }
        for(auto i:mp){
            if(i.second > 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};