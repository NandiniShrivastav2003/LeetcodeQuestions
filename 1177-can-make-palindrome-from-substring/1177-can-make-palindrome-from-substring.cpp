class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>>prefix;
        vector<int>temp(26,0);
        vector<bool>ans;
        prefix.push_back(temp);
        for(int i=0;i<s.size();i++){
            temp[s[i]-'a']++;
            prefix.push_back(temp);
        }
        for(auto q:queries){
            int l=q[0];
            int r=q[1];
            int k=q[2];
             int odd=0;
             vector<int>count=prefix[r+1];
          for(int i=0;i<26;i++){
                count[i]-=prefix[l][i];
                odd+=(count[i]%2);
            }
          
       odd-=(odd%2);
      ans.push_back((odd<=k*2)?true:false);
        }
        return ans;
        
    }
};