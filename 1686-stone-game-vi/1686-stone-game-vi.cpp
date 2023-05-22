class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
       priority_queue<pair<int,pair<int,int>>>pq;
        int n=a.size();
       for(int i=0;i<n;i++){
           pq.push({a[i]+b[i],{a[i],b[i]}});
       }
        int first=0;
        int second=0;
        bool alice=true;
            while(!pq.empty()){
            if(alice){
                first+=pq.top().second.first;
                pq.pop();
                alice=false;
            }
            else{
                second+=pq.top().second.second;
                pq.pop();
                alice=true;
            }
            
            
        }
        if(first > second){
            return 1;
        }
        else if(second > first){
            return -1;
        }
        return 0;
    }
};