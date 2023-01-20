struct Pair{
    int id;
    int st;
    int ct;
  
};
class Solution {
public:
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n,0);
        stack<Pair>st;
        for(int i=0;i<logs.size();i++){
            string log=logs[i];
            stringstream ss(log);
            string temp, temp2, temp3;
            getline(ss, temp, ':');
            getline(ss, temp2, ':');
            getline(ss, temp3, ':');

          
            if(temp2 == "start"){
                Pair p={stoi(temp),stoi(temp3),0};
             
                st.push(p);
            }
            else if(temp2 == "end"){
             
                Pair p=st.top();
             
                int interval=stoi(temp3)-p.st+1;
                int time=interval-p.ct;
                ans[p.id]=ans[p.id]+time;
               
                st.pop();
                if(!st.empty()){
                st.top().ct+=interval;
                }
            }
        }
        return ans;
    }
};