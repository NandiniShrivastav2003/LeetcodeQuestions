class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ans;
        int res=0;
        for(int i=0;i<nums.size();i++){
            ans=0;
          unsigned long long temp=nums[i];
            while(s.find(temp) != s.end()){
                ans++;
                 s.erase(temp);
                temp=temp*temp;
               
            }
            res=max(res,ans);
        }
        return res< 2?-1:res;
    }
};