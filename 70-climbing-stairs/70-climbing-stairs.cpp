class Solution {
public:
    void cal(int n,int memo[]){
    memo[1]=1;
       memo[2]=2;
      for(int i=3;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2];
       }
        
       return ;
   }
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n ==2 ){
            return 2;
        }
         int memo[n+1];
    cal(n,memo);
        return memo[n];
    }
};

    