class Solution {
public:
    int minSwaps(string s) {
       int count=0;
        int ans=0;
      int j=s.size()-1;
      for(int i=0;i<s.size();i++){
          if(s[i] == '['){
              count++;
          }
         else{
             count--;
          }
          if(count < 0){
              swap(s[i],s[j--]);
              ans++;
              count=1;
          } 
      
}
        return ans;
        
    }
};