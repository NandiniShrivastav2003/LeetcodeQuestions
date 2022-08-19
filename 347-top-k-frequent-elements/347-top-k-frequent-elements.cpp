class Solution {
public:
     static bool cmp(pair<int,int>A,pair<int,int>B){
        return A.second> B.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>A;
        for(auto it:m){
            A.push_back(it);
        }
        sort(A.begin(),A.end(),cmp);
        for(auto i:A){
            k--;
            ans.push_back(i.first);
            if(k == 0){
                break;
            }
        }
        return ans;
    }
};