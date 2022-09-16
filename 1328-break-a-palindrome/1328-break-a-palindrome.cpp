class Solution {
public:
    string breakPalindrome(string p) {
        bool flag=false;
        if(p.size() == 1){
            return "";
        }
        for(int i=0;i<p.size();i++){
            if(p[0] != 'a'){
                p[i] = 'a';
                    flag=true;
                     break;
            }
            if(p[i] == 'a'){
                continue;
            }
            else{
                if(p[i+1] != 'a'){
                p[i] = 'a';
                    flag=true;
                     break;
                }
                
               
            }
        }
        if(flag == false){
            p[p.size()-1]='b';
        }
        return p;
    }
};