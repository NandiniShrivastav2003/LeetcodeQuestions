class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        
        string s=to_string(n);
        if(s.size() == 1){
            return stoi(s);
        }
        int i=s.size()-1;
            while(i>0){
            if(s[i] >= s[i-1]){
                i--;
                continue;
            }
            else{
                if(s[i-1] >= '0' && s[i-1] <= '9'){
                s[i-1]=s[i-1]-1;
                }
                for(int j=i;j<s.size();j++){
                    s[j]='9';
                }
            }
        }
       // cout<<s<<endl;
        i=0;
        while(s[i] == '0'){
            s.erase(s.begin()+i);
            i++;
        }
        return stoi(s);
    }
};