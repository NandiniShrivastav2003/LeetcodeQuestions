#define mod 1000000007
class Solution {
public:
    
        int getmax(int n,vector<int>cuts){
            sort(cuts.begin(),cuts.end());
        int size=cuts.size();
        int maxCut=cuts[0];
        for(int i=1;i<size;i++){
            maxCut=max(maxCut,cuts[i]-cuts[i-1]);
        }
        return max(maxCut,n-cuts[size-1]);
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        return ((long) getmax(h,horizontalCuts)*getmax(w,verticalCuts))%mod;
    }
};