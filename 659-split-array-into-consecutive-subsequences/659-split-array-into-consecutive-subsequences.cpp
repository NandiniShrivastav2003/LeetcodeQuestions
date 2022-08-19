class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m,ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(int i : nums){
            if(!m[i]){continue;}
            m[i]--;
            if(ans[i-1] > 0){
                ans[i-1]--;
                ans[i]++;
            }
            else if(m[i+1] && m[i+2]){
                m[i+1]--;
                m[i+2]--;
                ans[i+2]++;
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};