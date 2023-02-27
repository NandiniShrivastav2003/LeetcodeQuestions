class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms){
       int ans=INT_MAX;
      for(int j=1;j<=6;j++){
          int count=0;
          int i;
        for( i=0;i<tops.size();i++){
            if(tops[i] == j){
                continue;
            }
            else if(bottoms[i] == j){
                    count++;
                }
            
            else{
               
                break;
            }
        
        
        }
          if(i == tops.size() && ans>count){
          ans=count;
          }
         
      }
        
 return ans == INT_MAX ? -1:ans;
   
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       int a=check(tops,bottoms);
        int b=check(bottoms,tops);
       
        if(a != INT_MAX && b != INT_MAX){
            return min(a,b);
        }
       if(a == INT_MAX){
          return b;
       }
        return a;

    }
};