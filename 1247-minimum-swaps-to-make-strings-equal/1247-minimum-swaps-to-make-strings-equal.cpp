class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cx1=0,cy1=0,cx2=0,cy2=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i] == s2[i]){
                continue;
            }
            if(s1[i] == 'x' ){
                cx1++;
            }
            else{
                cy1++;
            }
             if(s2[i] == 'x' ){
                cx2++;
            }
            else{
                cy2++;
            }
        }
        if((cx1+cx2) % 2 == 1 || (cy1+cy2) % 2 == 1){
            return -1;
        }
        int ans=(cx1/2)+(cy1/2)+(cx1%2)*2;
        return ans;
        
    }
};