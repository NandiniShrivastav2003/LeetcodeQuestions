class Solution {
public:
    bool check(string a,string b){
        for(int i=0;i<a.size();i++){
            if(a[i] > b[i]){
                 return false;
            }
        }
        return true;
        
    }
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return check(s1,s2) || check(s2,s1);
       
    }
};