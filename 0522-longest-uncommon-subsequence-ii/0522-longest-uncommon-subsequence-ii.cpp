class Solution {
public:
  
    bool check(string s,string t,int i,int temp){
        if(temp == s.size()){
            return true;
            
        }
        if(i >= t.size()){
            return false;
        }
        
        if(s[temp] == t[i]){
            
            temp=temp+1;
        }
        return check(s,t,i+1,temp);
    }
 
    int findLUSlength(vector<string>& strs) {
        int ans=INT_MIN;
        int temp=0;
        for(int i=0;i<strs.size();i++){
            int temp=strs[i].size();
            int f=1;
            for(int j=0;j<strs.size();j++){
                if(i != j){
               if(check(strs[i],strs[j],0,0)){
                   f=0;
                  break; 
               }
              

            }
            }
            if(f == 1){
                ans=max(ans,temp);
            }
            
        }
        return ans == INT_MIN?-1:ans;
        
    }
};