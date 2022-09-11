class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
     int ans[mp.size()];
        int j=0;
        for(auto i:mp){
            ans[j]=(i.second);
            j++;
        }
        int n=mp.size();
         sort(ans,ans+n);
        int res=0;
            int i=0;
            while(i<n-1){
                   
                if(ans[i] == ans[i+1]){
                    if(ans[i] == 0){
                        i++;
                        continue;
                    }
                    res++;
                   ans[i]=ans[i]-1;
                      i=0;
                     sort(ans,ans+n);
                  
                }
                else{
                i++;
                }
            }
        return res;
        
    }
};