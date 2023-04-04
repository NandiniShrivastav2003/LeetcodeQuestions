class Solution {
public:
    long long f(long long n){
        long long s=0;
        long long m=n;
        while(m != 0){
            long long r=m%10;
            s+=r;
            m=m/10;
        }
        return s;
    }
    long long makeIntegerBeautiful(long long n, int target) {
       long long x=f(n);
        if(x<=target){
            return 0*1LL;
        }
        long long n1=n;
        long long cnt=10;
        while(f(n1) > target){
            long long r=n1%cnt;
            n1=n1-r+cnt;
            cnt *= 10;
            
            
        }
        return n1-n;
       
    }
};