class Solution {
public:
    vector<int>res;
    void fillPrimes(vector<int>& prime, int high)
{
    bool ck[high + 1];
    memset(ck, true, sizeof(ck));
    ck[1] = false;
    ck[0] = false;
    for (int i = 2; (i * i) <= high; i++) {
        if (ck[i] == true) {
            for (int j = i * i; j <= sqrt(high); j = j + i) {
                ck[j] = false;
            }
        }
    }
    for (int i = 2; i * i <= high; i++) {
        if (ck[i] == true) {
            prime.push_back(i);
        }
    }
}
    void segmentedSieve(int low, int high)
{
    if (low<2 and high>=2){
        low = 2;
    }//for handling corner case when low = 1 and we all know 1 is not prime no.
    bool prime[high - low + 1];
  //here prime[0] indicates whether low is prime or not similarly prime[1] indicates whether low+1 is prime or not
    memset(prime, true, sizeof(prime));
 
    vector<int> chprime;
    fillPrimes(chprime, high);
         for (int i : chprime) {
        int lower = (low / i);
        //here lower means the first multiple of prime which is in range [low,high]
        //for eg: 3's first multiple in range [28,40] is 30         
        if (lower <= 1) {
            lower = i + i;
        }
        else if (low % i) {
            lower = (lower * i) + i;
        }
        else {
            lower = (lower * i);
        }
        for (int j = lower; j <= high; j = j + i) {
            prime[j - low] = false;
        }
    }
   
    for (int i = low; i <= high; i++) {
        if (prime[i - low] == true) {
          res.push_back(i);
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
         segmentedSieve(left, right);
        if(res.size()<2){
            return {-1,-1};
        }
        int a=-1,b=-1;
        vector<int>out;
        int diff=INT_MAX;
        for(int i=0;i<res.size()-1;i++){
            if(res[i+1]-res[i] <diff){
                diff=res[i+1]-res[i];
                a=res[i];
                b=res[i+1];
            }
        }
        
        out.push_back(a);
        out.push_back(b);
        
        return out;
    }
};