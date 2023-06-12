class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<int>dp(s.size());
        int c1=0;
        dp[0]=0;
        if(s[0] == '1'){
            c1+=1;
        }
       // cout<<c1<<" ";
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                dp[i]=dp[i-1];
                c1++;
                }
            else{
                dp[i]=min(dp[i-1]+1,c1);
                }
            }
        for(int i=0;i<s.size();i++){
            //cout<<dp[i]<<" ";
        }
        return dp[s.size()-1];
    }
};