class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0;int j=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ans;
        pq.push({nums1[0]+nums2[0],{0,0}});
    
        set<pair<int,int>>s;
            s.insert({0,0});
       
        while(k > 0 && !pq.empty()){
            auto a=pq.top();
            pq.pop();
            int val=a.first;
            int i=a.second.first;
            int j=a.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1 < n && s.find({i,j+1}) == s.end()){
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
            if(i+1 < m && s.find({i+1,j}) == s.end() ){
                pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                 s.insert({i+1,j});
            }
            k--;
        }
        return ans;
        
    }
};