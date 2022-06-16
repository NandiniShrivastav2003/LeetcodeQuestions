class Solution {
public:
   void cal(int n,int memo[]){
    memo[0]=0;
       memo[1]=1;
      for(int i=2;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2];
       }
        
       return ;
   }
    int fib(int n) {
        if(n == 0){
            return 0;
        }
         int memo[n+1];
    cal(n,memo);
        return memo[n];
    }
};