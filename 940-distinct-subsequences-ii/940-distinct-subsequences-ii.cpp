class Solution {
public:
    int distinctSubseqII(string s) {
      long long  int dp[s.size()];
        const int mod=1e9 + 7;
        dp[0]=2;
        unordered_map<char,int>m;
        m[s[0]]=0;
        for(int i=1;i<s.size();i++){
            if(m.find(s[i]) == m.end()){
                dp[i]=(2*dp[i-1])%mod;
            }
            else{
                  dp[i]=(2*dp[i-1]-(m[s[i]] == 0 ? 1: dp[m[s[i]]-1]))%mod;
            }
            m[s[i]]=i;
        }
        
        if(dp[s.size()-1] < 0){
             dp[s.size()-1] += mod;
        }
       return dp[s.size()-1] -1 ;
    }
};