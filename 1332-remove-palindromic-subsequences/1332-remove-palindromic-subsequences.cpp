class Solution {
public:
    bool isPallindrome(string s){
        int left=0;int right=s.size()-1;
        while(left<=right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.size() == 1 || isPallindrome(s)){
            return 1;
        }
        return 2;
    }
};