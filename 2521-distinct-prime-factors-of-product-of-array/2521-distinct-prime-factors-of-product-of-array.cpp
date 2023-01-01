class Solution {
public:
    set<int>s;
    void primeFac(int num){
        int c=2;
        while(num > 1){
            if(num % c == 0){
                s.insert(c);
                num=num/c;
            }
            else{
                c++;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
       int ans=0;
        for(int i=0;i<nums.size();i++){
            primeFac(nums[i]);
        }
        return s.size();
    }
};