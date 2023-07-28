class Solution {
public:
    int minOperations(vector<int>& a, vector<int>&b) {
        sort(a.begin(),a.end());
       
        int ans=b[0];
        for(int i=1;i<b.size();i++){
            ans=__gcd(ans,b[i]);
        }
        int c=0;
        for(int i=0;i<a.size();i++){
            if(ans == a[i] || (ans % a[i] == 0)){
                return c;
            }
            c++;
        }
        return -1;
        
    }
};