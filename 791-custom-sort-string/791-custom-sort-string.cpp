class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        string res="";
        for(int i=0;i<order.size();i++){
            for(int j=1;j<=mp[order[i]];j++){
                res+=order[i];
            
            }
            mp.erase(order[i]);
        }
        for(auto i:mp){
            while(i.second--){
                res+=i.first;
            }
        }
        return res;
    }
};