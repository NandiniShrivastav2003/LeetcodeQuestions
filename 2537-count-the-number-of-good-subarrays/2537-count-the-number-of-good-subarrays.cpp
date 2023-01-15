class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long  ans=0;
        int j=0;
        int n=nums.size();
        long long temp=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            temp+=(mp[nums[i]]-1);
            while(j<i && temp >= k){
                ans+=(n-i);
                mp[nums[j]]--;
                temp-=mp[nums[j]];
                j++;
                
            }
            
        }
        return ans;
    }
};