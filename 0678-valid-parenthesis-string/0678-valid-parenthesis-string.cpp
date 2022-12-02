class Solution {
public:
    bool checkValidString(string s) {
      stack<int>star;
        stack<int>par;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                par.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(par.empty()){
                  if(star.empty()){
                  return false;    
                  }  
                    else{
                        star.pop();
                        
                    }
                }
                else{
                    par.pop();
                }
            }
        }
        while(!par.empty()  && !star.empty()){
           if(par.top() > star.top()){
               return false;
           }
            par.pop();star.pop();
            
        }
        return par.empty();
    }
};