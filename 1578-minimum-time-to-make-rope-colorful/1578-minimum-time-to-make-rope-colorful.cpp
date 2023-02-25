class Solution {
public:
    int minCost(string colors, vector<int>& coins) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<colors.size();i++){
           if(st.empty() || colors[i] != colors[st.top()]){
               st.push(i);
               continue;
           } 
            else if(coins[i] < coins[st.top()] ){
               
               ans+=coins[i];
           }
            else{
                ans+=coins[st.top()];
                st.pop();
                st.push(i);
              
            }
           
        }
        return ans;
    }
};