class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size()-1;
       int left=0,right=n;
        char temp;
        while(left<=right){
            temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
};