class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int>st;
        int ans=1;
        for(int i=0;i<rolls.size();i++){
           
                st.insert(rolls[i]);
            
            if(st.size() == k){
                ans++;
                st.clear();
            }
        }
        return ans;
    }
};