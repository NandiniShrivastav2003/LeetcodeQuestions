class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        vector<int>temp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
                
            }
            mp.erase(arr2[i]);
        }
        for(auto it:mp){
            while(it.second --){
            temp.push_back(it.first);
            }
        }
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
        return ans;
    }
};