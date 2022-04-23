class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        typedef pair<int, int> pi;
        vector<int>res;
        
         priority_queue<pi, vector<pi>, greater<pi> > pq;
        for(int i=0;i<arr.size();i++){
          pq.push(make_pair(abs(arr[i]-x), arr[i]));
        }
        int j=0;
        while (j++<k) {
       res.push_back(pq.top().second);
          
        pq.pop();
    } 
        sort(res.begin(),res.end());
        return res;
    }
};