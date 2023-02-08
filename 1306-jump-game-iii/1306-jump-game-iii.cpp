class Solution {
public:
 set<int>s; 
    bool canReach(vector<int>& arr, int start) {
       queue<int>q;
        q.push(start);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            s.insert(a);
            if(arr[a] == 0){
                return true;
            }
            if(a+arr[a] >=0 && a+arr[a]<arr.size()){
                if(s.find(a+arr[a]) == s.end()) {
               q.push(a+arr[a]);
                }
            }
            if(a-arr[a] >=0 && a-arr[a]<arr.size()){
                 if(s.find(a-arr[a]) == s.end()) {
               q.push(a-arr[a]);
                 }
            }
               
                
        }
        return false;
        }
    
};