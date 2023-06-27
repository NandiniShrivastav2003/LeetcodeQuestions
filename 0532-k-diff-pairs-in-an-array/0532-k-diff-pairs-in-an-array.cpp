class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
      //  unordered_map<int,int>m;
        int ans=0;
        int prev=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(prev == nums[i]){continue;}
            int req=nums[i]+k;
            if(binary_search(nums.begin()+i+1,nums.end(),req)){
             //   m[nums[i]]=req;
              //  cout<<nums[i]<<" "<<req<<endl;
                ans++;
            }
            prev=nums[i];
        }
        return ans;
    }
};