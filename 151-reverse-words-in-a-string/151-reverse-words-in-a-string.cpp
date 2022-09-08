class Solution {
public:
    string trim(string str){
    const char* typeOfWhitespaces = " \t\n\r\f\v";
str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
str.erase(0,str.find_first_not_of(typeOfWhitespaces));
return str;
    }
    string reverseWords(string s) {
        stack<char>sp;
        string res="";
        for(int i=s.length()-1;i>=0;i--){
        
            if(s[i] == ' ' && sp.empty() == false ){
                while(!sp.empty()){
                res+=sp.top();
                sp.pop();
                }
                res+=' ';
               
            }
                else{
                    if(s[i] != ' '){
                    sp.push(s[i]);
                }
                }
            
        }
       while(!sp.empty()){
                res+=sp.top();
                sp.pop();
       }
      
        return trim(res);
    }
};