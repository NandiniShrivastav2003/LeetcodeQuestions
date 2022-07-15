class Solution {
public:
    static bool cmp(vector <int> &a, vector <int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& ans) {
         sort(ans.begin(),ans.end(),cmp);
  int n=ans.size();
        int res=1;
      
        for(int i=0;i<n;i++){
              int temp=ans[i][1];
            int fin=1;
            for(int j=i+1;j<n;j++){
                if(temp < ans[j][0] ){
                fin++;
                temp=ans[j][1];
                
            }
            }
            res=max(res,fin);
            
           
        }
   
        return res;
    }
};