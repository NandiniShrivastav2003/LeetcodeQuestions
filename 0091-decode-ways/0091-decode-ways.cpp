class Solution {
public:
    vector<string>ans;
    int res=0;
      unordered_map<string,int>mp;
    int encoding(string s,int i,string ans,vector<int>&dp){
        if(i>s.size()){
            return 0;
        }
        if(s[i] == '0'){
            return 0;
        }
        if(i == s.size()){
            
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
            dp[i]=encoding(s,i+1,ans,dp);
        if(s.substr(i,2) >= "0" && s.substr(i,2) <= "26"){
            
        
        dp[i]+=encoding(s,i+2,ans,dp);
        }
     return dp[i];
    }
    int numDecodings(string s) {
        int ans=0;
      
        char ch='A';
        vector<int>dp(101,-1);
        encoding(s,0,"",dp);
        
     return dp[0] == -1 ?0:dp[0];   
    }
};