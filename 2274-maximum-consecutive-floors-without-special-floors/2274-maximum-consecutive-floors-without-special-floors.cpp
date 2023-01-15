class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>&A) {
        sort(A.begin(),A.end());
        int res=0;
        res=max(abs(A[A.size()-1]-top),abs(A[0]-bottom));
        for(int i=1;i<A.size();i++){
            res=max(res,A[i]-A[i-1]-1);
        }
     return res;   
    }
};