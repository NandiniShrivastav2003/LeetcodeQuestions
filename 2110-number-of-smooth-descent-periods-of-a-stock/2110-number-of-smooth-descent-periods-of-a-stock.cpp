class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int i=1;int j=0;
        while(i<prices.size())
        {
            if( prices[i]+1 == prices[i-1]){
               i++;
            }
            else{
                long long  n=abs(i-j);
                ans+=n*(n+1)/2;
                
                j=i;
                i++;
            }
        }
        long long n=abs(j-i);
        
        ans+=n*(n+1)/2;
        return ans;
    }
};