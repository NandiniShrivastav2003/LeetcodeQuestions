class Solution {
public:
   static bool compare(vector<int>a,vector<int>b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),compare);
        priority_queue<int>pq;
        int c=0;
        int curr=0;
        for(int i=0;i<courses.size();i++){
            
                if(courses[i][0] + curr <= courses[i][1]){
                curr+=courses[i][0];
                    pq.push(courses[i][0]);
                  
                    }
            else if(!pq.empty() && pq.top() > courses[i][0]){
                curr-=pq.top();
                curr+=courses[i][0];
                
                pq.pop();
                pq.push(courses[i][0]);
             
            }
        }
        return pq.size();
    }
};