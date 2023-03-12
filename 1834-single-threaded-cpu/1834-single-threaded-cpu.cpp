class Solution {
public:
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<int>>temp;
        for(int i=0;i<tasks.size();i++){
            temp.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(temp.begin(),temp.end());
      
        long long  time=0;
        int j=0;
        while(j<tasks.size()||!pq.empty()){
            if(pq.empty() && time < temp[j][0]){
           time=temp[j][0];
            }
            while(j<temp.size() && time >= temp[j][0])
            {
                pq.push({temp[j][1],temp[j][2]});
                j++;
            }   
            auto [cputime,index]=pq.top();
            pq.pop();
            time+=cputime;
            ans.push_back(index);
          
        }
        return ans;
    }
};