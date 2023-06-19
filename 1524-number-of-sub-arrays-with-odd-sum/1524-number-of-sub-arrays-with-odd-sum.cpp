class Solution {
public:
    
       
    int numOfSubarrays(vector<int>& arr) {
       int even=0;
        int odd=0;
        int mod=1e9+7;
         long long int  ans=0;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum % 2 == 1){
                ans+=(even+1)%mod;
                odd++;
                
            }
            else{
                ans+=(odd)%mod;
                even++;
            }
            
        }
        return ans%mod;
    }
};