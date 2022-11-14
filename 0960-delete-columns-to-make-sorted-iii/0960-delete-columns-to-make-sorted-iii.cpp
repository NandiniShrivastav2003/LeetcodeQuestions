class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs[0].size();
        int ans=1;
        int lis[n];
        for(int i=0;i<strs[0].size();i++){
            lis[i]=1;
            for(int j=0;j<i;j++){
                if(checklexo(strs,i,j)){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
            ans=max(ans,lis[i]);
        }
        return n-ans;
    }
    bool checklexo(vector<string>& strs,int i,int j){
        for(string s:strs){
            if(s[i] < s[j]){
                return false;
            }
        }
        return true;
    }
};