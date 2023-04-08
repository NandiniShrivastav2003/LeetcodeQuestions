class Solution {
public:
   vector<int> power(int n){
        int i=0;
       vector<int>res;
       while(true){
           int x=pow(2,i);
          if(x == n){
            res.push_back({x});
              return res;
          }
           if(x > n){
               
               break;
           }
            i++;
       }
       res.push_back(pow(2,i-1));
       res.push_back(pow(2,i));
       return res;
    }
    
    int minOperations(int n) {
        int cnt=0;
        while(n != 0){
            vector<int>temp=power(n);
            if(temp.size() == 1){
                return cnt+1;
            }
            int small=temp[0];
            int big=temp[1];
           n=min(abs(small-n),abs(big-n));
            cnt++;
        }
        return cnt;
    }
};