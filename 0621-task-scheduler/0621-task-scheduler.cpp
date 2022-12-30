class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int>mp;
        for(char c:tasks){
            mp[c]++;
        }
        priority_queue<int>pq;
    for(auto i:mp){
        pq.push(i.second);
    }
        int ans=0;
        while(!pq.empty()){
            int time=0;
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
                
            }
            for(auto i:temp){
                if(i>0){
                pq.push(i);
                }
            }
          ans+= pq.empty() ? time:n+1;
        }
        return ans;
    }
};
 