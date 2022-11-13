class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i=0;
        int ans=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }
            else{
                int found=-1;
                int pos=j-1;
                char ch=s[i];
                while( pos > i){
                    if(s[pos] == ch){
                       found=pos;
                        break;
                    }
                    pos--;
                }
                if(found != -1){
                        for(int k=found;k<j;k++){
                        swap(s[k],s[k+1]);
                            ans++;
                        }
                        i++;j--;
                       
                    }
                else{
                    swap(s[i],s[i+1]);
                    ans++;
                }
                   
                }
                
            }
        
        
        return ans;
    }
};