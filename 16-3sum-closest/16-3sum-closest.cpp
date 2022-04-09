class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum;
        int res=INT_MAX;
        int fin;
        for(int i=0;i<nums.size()-2;i++){
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                sum=nums[i]+nums[low]+nums[high];
                if( sum == target){
                    return sum;
                }
                else if(sum > target){
                    high--;
                }
                else{
                    low++;
                }
                if(abs(res)> abs(sum-target)){
                    res=sum-target;
                    fin=sum;
                    
                }
            }
        }
        return fin;
    }
};