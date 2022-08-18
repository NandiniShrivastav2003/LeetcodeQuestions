class Solution {
public:
    static bool cmp(pair<int,int>A,pair<int,int>B){
        return A.second > B.second;
    }
    int minSetSize(vector<int>& arr) {
     unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>A;
        for(auto i:mp){
            A.push_back(i);
        }
        sort(A.begin(),A.end(),cmp);
        int N=0;
        int ans=0;
        
            for(auto it : A){
                N+=it.second;
                 ans++;
                if(N >= n/2){
                    break;
                }
               
            }
    return ans;
    }
};