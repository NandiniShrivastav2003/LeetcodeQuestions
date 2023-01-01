class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans=0;
        long num=0;
        for(int i=0;i<s.size();i++){
           
            if(num * 10 +(s[i]-'0') < k){
                 num=num*10+(s[i]-'0');
            }
            else{
                num=(s[i]-'0');
                if(num > k){
                    return-1;
                }
                ans++;
            }
        }
        if(num < k){
            ans++;
        }
        return ans;
    }
};