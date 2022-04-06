class Solution {
public:
    int strStr(string h, string n) {
        char t=n[0];
        int j;
        for(int i=0;i<h.size();i++){
           j=0;
            if(t == h[i]){
                if(h.size()-i <  n.size()){return -1;}
                int first=i;
                int c=1;
                while(j<n.size()){
                    if(h[first] != n[j]){c=0;break;}
                    first++;j++;
                }
                if(c == 1){
                return i;
                }
            }
        }
        return -1;
    }
};