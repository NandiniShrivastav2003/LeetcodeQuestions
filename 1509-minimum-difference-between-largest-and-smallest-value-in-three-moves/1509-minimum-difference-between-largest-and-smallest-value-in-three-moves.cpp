class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() <= 3){
            return 0;
        }
        int n=nums.size();
       int a= nums[n-1];int b=nums[3];
        int c=nums[n-2];int d=nums[2];
        int p=nums[n-3];int q=nums[1];
        int r=nums[n-4];int s=nums[0];
        int x=min(p-q,r-s);int y=min(a-b,c-d);
        return min(x,y);
    }
};