class Solution {
public:
    int getSum(int a, int b) {
        int x=a^b;
        int carry=(a&b & 0x7fffffff);
        if(carry == 0){return x;}
        else{return getSum(x,carry<<1);} 
    }
};