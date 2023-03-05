class Solution {
public:
 
    vector<vector<int>> getSkyline(vector<vector<int>>& arr) {
       multiset<int>pq;
        vector<pair<int,int>>data;
       
        for(int i=0;i<arr.size();i++){
         vector<int> it=arr[i];
                int x=it[0];
                int y=it[1];
                int ht=it[2];
               data.push_back({x,-ht});
               data.push_back({y,ht});
            
        }
        pq.insert(0);
        vector<vector<int>>ans;
        int maxi=0;
       sort(begin(data), end(data), [](const auto& a, const auto& b) {
            return (a.first != b.first) ? a.first < b.first : a.second < b.second;
        });
       
        for(auto it:data){
             if(it.second < 0){
              pq.insert(abs(it.second));   
             }
            else{
            pq.erase(pq.find(it.second));
            }
                 
                    
                
                 auto temp=*(pq.rbegin());
                if(temp != maxi){
                   maxi=temp;
                    ans.push_back({it.first,maxi});
                }
                
            
           
        }
        return ans;
        
        
    }
};