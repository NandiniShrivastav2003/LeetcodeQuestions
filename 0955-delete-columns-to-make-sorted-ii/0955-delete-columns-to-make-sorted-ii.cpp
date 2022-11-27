class Solution {
public:
  /*  Approach:
1.Initially take vector of empty string and try to add each character from string present in its respective row
2.Now compare all this string and check if they are in lexicographical order or not.
3.If they are not in lexicographical order remove newly added element from each string
*/
    int minDeletionSize(vector<string>& s) {
      int n=s.size();
      int m=s[0].size();
        vector<string>vec(n,"");
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              vec[j]+=s[j][i];
          }
          int var=1;
          for(int j=1;j<n;j++){
              if(vec[j] < vec[j-1]){
                  var =-1;
                  break;
              }
          }
          if(var == -1){
              for(int j=0;j<n;j++){
                  vec[j].pop_back();
              }
          }
      }  
        return m-vec[0].size();
    }
};