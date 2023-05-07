class Solution {
public:
    int lastRemaining(int n) {
        int start=1;
        int steps=1;
        bool left=true;
        while(n  > 1){
            if(left || n % 2 == 1){
                start+=steps;
            }
            steps*=2;
            n=n/2;
            left=!left;
        }
        return start;
    }
};