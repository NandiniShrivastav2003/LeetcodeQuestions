class Solution {
public:
    int check(int n){
        if(n == 1){
            return 0;
        }
          if( n == 2){
                return 1;
            }
        for(int i=1;i<n;i++){
            if(n%i == 0){
               return check(n-i) == 1 ? 0:1;
            }
          
        }
        return 0;
    }
    bool divisorGame(int n) {
        return check(n) == 0 ? false:true;
    }
};