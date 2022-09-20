class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //multimap differs from map in the way that it can store duplicate keys also and by default it keeps key in ascending order.
        multimap<int,int>mp;
        int n=points.size();
        for(int i=0;i<n;i++){
            int a=points[i][0],b=points[i][1];
            int d=(a*a)+(b*b);
            mp.insert({d,i});
            
        }
        vector<vector<int>>ans;
    for(auto i:mp){
        
        ans.push_back(points[i.second]);
        k--;
        if(k == 0){
            break;
        }
    }
        return ans;
    }
};