class Solution {
public:
    int minNumberOfFrogs(string str) {
        int cnt=0;
        int res=0;
        int c=0,r=0,o=0,a=0,k=0;
        vector<int>ans;
        for(int i=0;i<str.size();i++){
            if(str[i] == 'c'){
                cnt++;
               c++;
                
            }
            else if( str[i] == 'k'){
                cnt--;
                k++;
            }
            else if(str[i] == 'r'){
                r++;
            }
            else if(str[i] == 'o'){
                o++; 
                
            }
            else{
                a++;
            }
            
            ans.push_back(cnt);
            res=max(res,cnt);
            if(c<r || r<o || o<a || a<k){
                
                return -1;
            }
        }
       if(c != r || r != o || o != a || a != k){
           return -1;
       }
      
        return res;
    }
};