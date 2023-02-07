class Solution {
public:
  //  TC-O(NLogN)
    vector<int> longestObstacleCourseAtEachPosition(vector<int>&nums) {
       vector<int>lis;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(lis.empty() || lis[lis.size()-1] <= x){
                lis.push_back(x);
                nums[i]=lis.size();
            }
            else{
                int ind=upper_bound(lis.begin(),lis.end(),x)-lis.begin();
                lis[ind]=x;
                nums[i]=ind+1;
            }
        }
           return nums;
           
    }
};