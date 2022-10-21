class Solution {
public:
     vector<int>temp;
        vector<vector<int>>res;
    void comb(vector<int>nums,int k,int idx){
        if(k == 0){
            res.push_back(temp);
         //   temp.clear();
            return ;
        }
        if(idx >= nums.size()){
            return ;
        }
      
        for(int i=idx;i<nums.size();i++){
              temp.push_back(nums[i]);
            comb(nums,k-1,idx+1);
            temp.pop_back();
            idx=idx+1;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
       
        comb(nums,k,0);
        return res;
    }
};