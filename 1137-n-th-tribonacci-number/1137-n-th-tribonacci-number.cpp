class Solution {
public:
     void cal(int n,int memo[]){
    memo[0]=0;
       memo[1]=1;
     memo[2]=1;
      for(int i=3;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2]+memo[i-3];
       }
        
       return ;
   }
    int tribonacci(int n) {
        if(n==0){return 0;}
         if(n == 2 || n == 1  ){
            return 1;
        }
         int memo[n+1];
    cal(n,memo);
        return memo[n];
    }
};

   