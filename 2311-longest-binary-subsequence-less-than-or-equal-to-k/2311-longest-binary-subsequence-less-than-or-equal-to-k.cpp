class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count=0;
        long long int res=0;
        int len=0;
        int stop=1;
        long long temp=0;
       for(int i=s.size()-1;i>=0;i--){
           if(s[i] == '0'){
               count++;
               len++;
           }
           else if(stop == 1 && count < 31) {
                 temp=pow(2,count);
               if(res+temp <= k){
                   res+=temp;
                    len++;
               }
               else{
                   stop=0;
               }
               count++;
              
           }
       }
        return len;
    }
};