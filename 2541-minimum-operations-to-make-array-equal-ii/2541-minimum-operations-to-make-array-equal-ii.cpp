class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long up=0;
        long long down=0;
        long long ans=0;
        if(nums1 == nums2){
            return 0;
        }
        if(k == 0){
            return -1;
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] == nums2[i]){
                continue;
            }
            if(abs(nums1[i]-nums2[i]) % k != 0){
                return -1;
            }
             if(nums1[i] > nums2[i]){
                ans+=(nums1[i]-nums2[i])/k;
                up+=(nums1[i]-nums2[i]);
            }
            else {
                ans+=(nums2[i]-nums1[i])/k;
                down+=(nums2[i]-nums1[i]);
            }
        }
        if(up != down){
            return -1;
        }
        return ans/2;
    }
};