class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
       
    int n=a.size();
        int lis[n];
        lis[0]=1;
        for(int i=1;i<n;i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(a[j] < a[i]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
            
        }
        int res=lis[0];
        for(int i=1;i<n;i++){
            res=max(res,lis[i]);
        }
        return res;
    
    }
};