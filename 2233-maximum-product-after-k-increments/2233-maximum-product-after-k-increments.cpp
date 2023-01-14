class Solution {
public:
    int mod=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int temp=pq.top();pq.pop();
            pq.push(temp+1);
        }
       long long ans=1;
        while(!pq.empty()){
            ans=ans*pq.top();
            ans=ans%mod;
            pq.pop();
        }
        return ans;
    }
};