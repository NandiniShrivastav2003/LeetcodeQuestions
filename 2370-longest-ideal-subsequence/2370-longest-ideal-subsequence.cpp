class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[26]={0};
        int maxi=1;
        for(char &c:s){
          int i=c-'a';
            dp[i]+=1;
            for(int j=max(0,i-k);j<=min(25,i+k);j++){
                if(j != i){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};