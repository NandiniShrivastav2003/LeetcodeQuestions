class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>>m;
        for(int i=0;i<indices.size();i++){
            m.push_back({indices[i],i});
        }
        sort(m.rbegin(),m.rend());
        for(auto i:m){
            int j=i.first;
           string S=sources[i.second];
            string t=targets[i.second];
            if(s.substr(j,S.size()) == S){
                s=s.substr(0,j)+ t +s.substr(j+S.size());
            }
        }
        return s;
    }
};