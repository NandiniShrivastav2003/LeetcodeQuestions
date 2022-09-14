class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string,int>m;
        for(auto i:nums){
            m[i]++;
        }
        int count = 0;
        int n=target.size();
        for(int i=0;i<target.size();i++){
            string s1=target.substr(0,i);
            string s2=target.substr(i,n);
            if(s1 == s2){
                count += m[s1]*(m[s2]-1);
            }
            else{
                count += m[s1]*m[s2];
            }
        }
        return count;
    }
};