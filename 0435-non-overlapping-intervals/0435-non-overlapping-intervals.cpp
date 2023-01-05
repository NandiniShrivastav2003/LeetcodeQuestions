class Solution {
public:
   static bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>&arr) {
        sort(arr.begin(),arr.end(),comp);
        int end=arr[0][1];
        int ans=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] < end){
                ans++;
               
            }
            else{
                end=arr[i][1];
            }
        }
        return ans;
    }
};