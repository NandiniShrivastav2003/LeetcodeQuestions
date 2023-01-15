class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map<int,int>mp,ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(!mp[nums[i]]){
                continue;
            }
            else{
                for(int j=nums[i];j<nums[i]+k;j++){
                    if(mp[j] <= 0){
                        
                        return false;
                    }
                    mp[j]--;
                }
                
            }
        }
        return true;
    }
};