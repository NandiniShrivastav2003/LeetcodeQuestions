class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int right=0;int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                if(right%2>0){
                    right--;
                    res++;
                }
                right+=2;
            }
            else{
                right--;
                if(right<0){
                    right+=2;
                    res++;
                }
            }
        }
        return right+res;
    }
};