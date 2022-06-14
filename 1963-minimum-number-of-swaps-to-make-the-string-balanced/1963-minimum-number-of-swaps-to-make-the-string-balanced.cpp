class Solution {
public:
    int minSwaps(string s) {
        int res=0;
        int last= s.size()-1;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '['){
                count++;
            }
            else {
                count--;
            }
            if(count<0){
                swap(s[i],s[last]);
                last--;
                res++;
                count=1;
            }
            if(i>last){
                break;
            }
        }
        return res;
    }
};