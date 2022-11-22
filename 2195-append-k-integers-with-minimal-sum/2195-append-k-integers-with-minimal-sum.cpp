class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<long long>s;
         long sum=(long(k)*(long(k+1)))/2;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(long long i:s){
            if(i <= k){
                sum-=i;
                sum+=(k++)+1;
                
            }
            else{
                break;
            }
        }
        return sum;
    }
};