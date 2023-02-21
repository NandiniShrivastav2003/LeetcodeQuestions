class Solution {
public:
    int longestPalindrome(vector<string>& words) {
     
       map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        int count=0;
        bool flag=false;
       for(auto i:words){
          string  temp=i;
           string rev=temp;
           cout<<temp<<endl;
           reverse(rev.begin(),rev.end());
           if(temp != rev && mp[temp] > 0 && mp[rev] >0){
               count+=4;
               mp[temp]--;
               mp[rev]--;
           }
           else if(temp == rev && mp[temp] >1 ){
               count+=4;
               mp[temp]-=2;
           }
           else if(temp == rev && mp[temp] > 0  && !flag ){
               flag=true;
               count+=2;
               mp[temp]--;
           }
        }
        return count;
    }
};