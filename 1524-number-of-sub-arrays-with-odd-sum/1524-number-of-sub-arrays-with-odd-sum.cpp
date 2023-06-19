class Solution {
public:
    
       //intution-we use the concept of
    
    // even+even=even
    //  odd+odd=even
        //since we need odd sum subarray we count then even and odd sum 
        //1.if sum is odd it means odd-even=odd (we add even count + 1 ) //+1 for curr sum which is odd
        //2.if sum is even it means even-odd=odd(we add count of odd)
        // even+odd=odd
        // odd+even=odd
        
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