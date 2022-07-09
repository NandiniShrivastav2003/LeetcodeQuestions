
class Solution {
public:
    
    bool isPalindrome(string &s, int start, int end) {
        
        while(start < end) {
            
            if(s[start] != s[end]) return false;
            
            start += 1;
            end -= 1;
            
        }
        
        return true;
        
    }
    
    int solve(string &s, int start, int end,vector<vector<int>> &dp) {
        
        if(dp[start][end] != -1) return dp[start][end];
        
        if(start >= end) return dp[start][end] = 0 ;
        
        if(isPalindrome(s,start,end) == true)
            return dp[start][end] = 0;
        
        int ans = INT_MAX;
        
        for(int ctr = start ; ctr < end ; ctr ++ ) {
            
            if(isPalindrome(s,start,ctr)==false)
                continue;
            
            int tempAns = solve(s,start,ctr,dp) + solve(s,ctr+1,end,dp) + 1;
            
            if(tempAns < ans) ans = tempAns;
        }
        
        return dp[start][end] = ans;
        
    }
    
    int minCut(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,-1));
        return solve(s,0,s.length()-1,dp);
    }
};