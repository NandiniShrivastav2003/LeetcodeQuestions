class Solution {
public:
   
    int nthUglyNumber(int n) {
       vector<int>res;
        res.push_back(1);
       int i=0;int j=0;int k=0;
        int ans=1;
       while(ans<n){
           res.push_back(min(res[i]*2,min(res[j]*3,res[k]*5)));
           if(res.back() == res[i]*2){
               i++;
           }
            if(res.back() == res[j]*3){
               j++;
           }
            if(res.back() == res[k]*5){
               k++;
           }
           ans++;
       }
        return res.back();
        
    }
};