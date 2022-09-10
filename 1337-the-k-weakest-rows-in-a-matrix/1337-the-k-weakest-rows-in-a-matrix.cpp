class Solution {
public:
   static bool cmp(pair<int,int>&A,pair<int,int>&B){
       return A.first < B.first;
   
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                
                if(mat[i][j] == 1){
                    count++;
                }
                else{
                   
                    break;
                }
            }
             ans.push_back({count,i});
        }
        sort(ans.begin(),ans.end());
        vector<int>ret;
        for(auto i:ans){
            k--;
            if(k < 0){
                break;
            }
            ret.push_back(i.second);
        }
    return ret;
    }
};

