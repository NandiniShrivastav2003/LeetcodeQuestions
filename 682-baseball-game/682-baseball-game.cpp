class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(int i=0;i<ops.size();i++){
            if(ops[i] == "C"){
                s.pop();
            }
            else if(ops[i] == "D"){
                s.push(s.top()*2);
            }
            else if(ops[i] == "+"){
                int n1=s.top();
                s.pop();
                int n2=s.top();
                s.push(n1);
                s.push(n1+n2);
            }
            else{
                s.push(stoi(ops[i]));
            }
        }
        int res=0;
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        return res;
    }
};