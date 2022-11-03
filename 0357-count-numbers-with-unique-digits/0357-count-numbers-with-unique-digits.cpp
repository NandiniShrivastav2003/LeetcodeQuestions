class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int ans=1;
        if(n == 0){
            return ans;
        }
    int temp=9;
          ans=ans+temp;
        if(n == 1){
          
            return ans;
        }
         temp=temp*temp;
        ans=ans+temp;
if(n == 2){
    
    return ans;
}
       int d=9;
        for(int i=3;i<=n;i++){
            temp=temp*(d-1);
    ans+=temp;
            --d;
        }
 return ans;
    }
};     