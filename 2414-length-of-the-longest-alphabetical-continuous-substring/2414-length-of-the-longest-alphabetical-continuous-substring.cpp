class Solution {
public:
    int longestContinuousSubstring(string s) {
     int j=1;
    long temp=0;
        int res=0;
        while(j<s.size()){
            char ch1=s[j-1]+1;
            char ch2=s[j];
            if(ch1 == ch2){
            temp++;
               
            }
            else{
                if(temp>res){
                    res=temp;
                }
                temp=0;
                
            }
           
            j++;
        }
        if(temp>res){
                    res=temp;
                }
        return res+1;
    }
};