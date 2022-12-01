class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 == 1){
            return false;
        }
        int a=0,b=0,c=0;
        for(int i=0;i<s.size();i++){
            if(locked[i] == '0'){
                c++;
            }
            else{
                if(s[i] == '('){
                    a++;
                }
                else{
                    b++;
                }
            }
            if(b > a+c){
                return false;
            }
        }
        a=0,b=0,c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i] == '0'){
                c++;
            }
            else{
                if(s[i] == '('){
                    a++;
                }
                else{
                    b++;
                }
            }
            if(a > b+c){
                return false;
            }
        }
        return true;
    }
};