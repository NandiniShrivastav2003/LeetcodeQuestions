class Solution {
public:
    int lastRemaining(int n) {
        //we will use math and some observations like if there is right turn then our start pos willnot change as value will be cut from right side which does not cut our curr pos 
        //ex- 2 4 6 8 here if our curr pos=2 and right = true then 2 will remain same 
        //but 2 4 6 8 10 then 2 will change.hence if(n% 2 ==  1){
       // then change start.
    //}
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