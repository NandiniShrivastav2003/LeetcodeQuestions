class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> o1,o2,e1,e2;
        for(auto &i: nums){
            if(i&1){
                o1.push_back(i);
            }else{
                e1.push_back(i);
            }
        }
        for(auto &i: target){
            if(i&1){
                o2.push_back(i);
            }else{
                e2.push_back(i);
            }
        }
        long long int ans = 0;
        sort(o1.begin(),o1.end());
        sort(o2.begin(),o2.end());
        sort(e1.begin(),e1.end());
        sort(e2.begin(),e2.end());
        int i = 0, n = o1.size();
        for(i = 0; i < n; i++){
            ans += abs(o1[i]-o2[i]);
        }
        n = e1.size();
        for(i = 0; i < n; i++){
            ans += abs(e1[i]-e2[i]);
        }
        return (ans>>2);   
    }
};