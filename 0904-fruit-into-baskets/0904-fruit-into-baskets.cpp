class Solution {
public:
    int totalFruit(vector<int>& f) {
        int ans=0;
        int left=0;
        unordered_map<int,int>s;
        int i;
        for( i=0;i<f.size();i++){
             s[f[i]]++;
            while(s.size()>2 ){
                
                ans=max(ans,i-left);
                if(s[f[left]] > 1){
                    s[f[left]]--;
                }
                else{
                   s.erase(f[left]);  
                }
               
                left++;
            }
        }
          // cout<<left<<endl;

         ans=max(ans,i-left);
        return ans;
    }
};