class Solution {
public:
    vector<vector<int>>res;
    void combSum2(int i,vector<int>&arr,vector<int>target,int sum){
        if(sum == 0){
            res.push_back(target);
            return;
        }
        if(i>arr.size() || sum<0){
            return;
        }
        for(int j=i;j<arr.size();j++){
            if( i != j && arr[j] == arr[i]){
                continue;
            }
               target.push_back(arr[j]);
               combSum2(j+1,arr,target,sum-arr[j]);
            target.pop_back();
        }
       
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>out;
        combSum2(0,candidates,out,target);
    sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }
};