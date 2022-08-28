class Solution {
public:
    string getHint(string secret, string guess) {
     unordered_map<char,int>s;
        int b=0;
        int c=0;
        string res="";
        for(int i=0;i<guess.size();i++){
            if(secret[i] == guess[i]){
                b++;
            }
            else{
                s[secret[i]]++;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i] != guess[i]){
                if(s.find(guess[i]) != s.end() && s[guess[i]] > 0){
                    c++;
                    s[guess[i]]--;
                    
                }
            }
        }
        res = to_string(b) + "A" + to_string(c) + "B";
        return res;        
    }
};