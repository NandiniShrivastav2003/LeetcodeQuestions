class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
    
    vector<int>res;
    for(int i=0;i<s.size();i++){
        if(s[i] == '+'  || s[i] == '-' || s[i] == '*'){
            vector<int>res1=diffWaysToCompute(s.substr(0,i));
             vector<int>res2=diffWaysToCompute(s.substr(i+1));
            for(auto k:res1){
                for(auto j:res2){
                    if(s[i] == '+'){
                        res.push_back(k+j);
                    }
                    if(s[i] == '-'){
                        res.push_back(k-j);
                    }if(s[i] == '*'){
                        res.push_back(k*j);
                    }
                }
            }
        }
    }
        if(res.empty()){
            res.push_back(stoi(s));
        }
        return res;
    }
};