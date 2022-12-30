class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles == 0){
            return target-1;
        }
        int c=0;
        while(target != 1){
            if(maxDoubles != 0 && target % 2 == 0){
            target =target/2;
                
                c++;
                maxDoubles--;
                }
           else{
                target -- ;
                c++;
            }
        }
        return c;
    }
};