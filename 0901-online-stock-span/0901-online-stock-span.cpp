class StockSpanner {
public:
   int c=0;
     stack<pair<int,int>>st;
    StockSpanner() {
        
    }
     int next(int price) {
         int ans;
         if(st.empty()){
             ans=1;
         }
         else{
             while(!st.empty() && st.top().first <= price){
                st.pop();
             }
             if(!st.empty()){
              ans=(c-st.top().second);
             }
             else{
                 ans=c+1;
             }
         }
        st.push({price,c});
         c++;
         return ans;
	
    }
};

