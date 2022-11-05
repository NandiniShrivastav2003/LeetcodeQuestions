class Solution {
public:
//     bool isPerfectSquare(int num) {
//         if (num == 1) return true;
//         long long lo = 1;
//         long long hi = num / 2;
        
//         while(lo <= hi) {
//             long long mid = (lo + hi) / 2;
//             long long sq = mid * mid;
            
//             if (sq == num) return true;
//             else if (sq < num) {
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }
        
//         return false;
//     }
     bool isPerfectSquare( long int n) {
        if(n==1 || n==0)return true;
      long int s=0,e=n;
        
        while(s<=e){
            long int m=s+(e-s)/2;
            if(m*m==n)return true;
           else if(m*m<n)
                s=m+1;
            else e=m-1;
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        int lo=0;
        int hi=c/2;
        while(lo<=hi){
            double mid=(lo+hi)/2;
            if((c-mid*mid) < 0){
                hi=mid-1;
            }
           else if(isPerfectSquare(c-mid*mid) ){
                return true;
            }
        lo++;
        }
        return false;
    }
};