class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long m=nums1.size();
        long n=nums2.size();
        long mod=1e9+7;
        int i=0;
        int j=0;
        long x=0;
        long y=0;
        while(i < m || j < n){
            if(i<m && ((j == n) || (nums1[i] < nums2[j]))){
                x+=nums1[i++];
            }
            else if(j < n && ((i == m) || (nums2[j] < nums1[i]))){
                y+=nums2[j++];
            }
            else{
                x=y=max(x,y)+nums1[i];
                i++;
                j++;
            }
        }
        return max(x,y)%mod;
    }
};