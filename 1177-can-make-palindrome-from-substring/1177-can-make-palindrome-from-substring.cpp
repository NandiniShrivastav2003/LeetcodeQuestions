class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        //we will maintain count of frequencies of string s till index i.
        vector<vector<int>>prefix;
        vector<int>temp(26,0);
        vector<bool>ans;
        //for conditions like [0,4] we will push initial 0= value as temp[0,...0]
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
              //subtract freq[r+1]-freq[l]
                count[i]-=prefix[l][i];
              
                odd+=(count[i]%2);
            }
          
       odd-=(odd%2); // if odd is odd like 5 then we will subtract 1 as abcba //atmost one can be odd.
            
      ans.push_back((odd<=k*2)?true:false); //  we can change odds/2 elements to match other odds/2 elements so odd/2<=k or odd<=2*k
        }
        return ans;
        
    }
};