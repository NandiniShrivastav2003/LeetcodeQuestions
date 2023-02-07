class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size());
        vector<int>ans;
        vector<int>hash(nums.size());
       for(int i=0;i<nums.size();i++){
           hash[i]=i;
       }
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if( nums[i] % nums[j] == 0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                    
                }
            }
            
        }
        int end;
        int temp=INT_MIN;
        for(int i=0;i<nums.size();i++){
          if(temp<dp[i]){
              temp=dp[i];
              end=i;
              
          }
          
        }
       
       
        int i=end;
     while(hash[i] != i){
        ans.push_back(nums[i]);
         if(i == 0){
             break;
         }
         i=hash[i];
        
      }
        ans.push_back(nums[i]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};