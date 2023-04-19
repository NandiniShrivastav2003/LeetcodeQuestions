class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        long res[nums.size()];
     
        int ans=0;
        int c=0;
        res[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            res[i]=(res[i-1]+nums[i]);
           
        }
        for(int i=0;i<nums.size();i++){
             if(res[i] > 0){
                 c++;
             }
        }
        return c;
    }
};