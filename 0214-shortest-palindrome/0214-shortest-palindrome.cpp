class Solution {
public:
    string shortestPalindrome(string s) {
       int i=0;
        int n=s.size();
        for(int j=n-1;j>=0;j--){
            if(s[i] == s[j]){
                i++;
            }
        }
        if(i == n){
            return s;
        }
        string rev=s.substr(i,n);
        reverse(rev.begin(),rev.end());
        return rev+shortestPalindrome(s.substr(0,i))+s.substr(i,n);
    }
};