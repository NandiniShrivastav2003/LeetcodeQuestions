class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
       int ans=0;int cnt=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(a[0][1]);
        for(int i=1;i<a.size();i++){
            if(!pq.empty() && pq.top() < a[i][0]){
                pq.pop();
                pq.push(a[i][1]);
            }
            else {
                pq.push(a[i][1]);
                cnt++;
            }
            
        }
        return cnt;
    }
};