class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        set<int>s;
        int s1=0;int s2=0;
        for(int i=0;i<B.size();i++){
            s.insert(B[i]);
            s2+=B[i];
        }
         for(int i=0;i<A.size();i++){
          
            s1+=A[i];
        }
        int temp=(s2-s1)/2;
          for(int i=0;i<A.size();i++){
              if(s.find(A[i]+temp) != s.end()){
                  return {A[i],temp+A[i]};
              }
          }
        return {0,0};
    }
};