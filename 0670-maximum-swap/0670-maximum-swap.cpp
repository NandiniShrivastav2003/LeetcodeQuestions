class Solution {
public:
    int maximumSwap(int num) {
        unordered_map<int,int>mp;
         string s=to_string(num);
        for(int i=0;i<s.size();i++){
            mp[s[i]-'0']=i;
        }
       
        for(int i=0;i<s.size();i++){
            for(int j=9;j>s[i]-'0';j--){
                if(mp[j] > i){
                    swap(s[mp[j]],s[i]);
                    return stoi(s);
                }
            }
        }
        return stoi(s);
    }
};