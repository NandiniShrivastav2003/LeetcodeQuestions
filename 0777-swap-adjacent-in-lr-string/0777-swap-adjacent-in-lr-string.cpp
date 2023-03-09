class Solution {
public:
    bool canTransform(string start, string end) {
        int n=start.size();
        string s1="",s2="";
        for(int i=0;i<n;i++){
            if (start[i] != 'X' ){
                s1+=start[i];
            }
            if(end[i] != 'X'){
                s2+=end[i];
            }
        }
        if(s1 != s2){
            return false;
        }
        
        for(int i=0,j=0;i<n && j<n;){
            if(start[i] == 'X'){
                i++;
                continue;
            }
            else if(end[j] == 'X'){
                j++;
                continue;
            }
            else if(start[i] == 'R' && end[j] == 'R' && i > j || start[i] == 'L' && end[j] == 'L' && i < j ){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};