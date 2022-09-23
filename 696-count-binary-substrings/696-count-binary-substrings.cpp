class Solution {
public:
    int countBinarySubstrings(string s) {
        int i=0;
        int n=s.size();
        // string ans="";
        int count=0;
        vector<int>grp;
        while(i<s.size()){
            if(s[i] == '0'){
                while(s[i] != '1' && i<n){
                count++;
                    i++;
                }
            }
            else{
                while(s[i] != '0' && i<n){
                    count++;
                    i++;
                }
            }
           
        grp.push_back(count); 
            count=0;
        }
       
        int res=0;
        for(int i=0;i<grp.size()-1;i++){
          
            res+=min(grp[i],grp[i+1]);
        }
        return res;
    }
};