
       
       
    
class Solution {
public:
    static bool cmp(string &s1,string &s2){
            if(s1.size() == s2.size()){
                return s1<s2;
            }
            return s1.size()<s2.size();
        }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
       
        
       return nums[nums.size()-k];
    }
};