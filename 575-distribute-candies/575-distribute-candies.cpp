class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
     int n=candyType.size()/2;
        unordered_map<int,int>m;
        for(int i=0;i<2*n;i++){
            m[candyType[i]]++;
        }
        if(n>=m.size()){
            return m.size();
        }
        if(m.size()>=n){
            return n;
        }
        return n-m.size();
    }
};