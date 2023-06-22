class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
       long long ans=0;
       vector<long long >zero(n,0);
        vector<long long>one(n,0);
        zero[0]=s[0] == '0';
        one[0]=s[0] == '1';
       
           for(int i=1; i<s.size(); i++)
        {
            zero[i] = zero[i-1] + (s[i] == '0');
            one[i] = one[i-1] + (s[i] == '1');
              
        }
        for(int i=1;i<s.size();i++){
            if(s[i] == '1'){
               ans+=(long long)(zero[i] * (zero[n-1]-zero[i]));
            }
            else{
                ans+=(long long)(one[i] * (one[n-1]-one[i]));
            }
        }
        return ans;
        
            
        
     
        
        return ans;
        
        
    }
};