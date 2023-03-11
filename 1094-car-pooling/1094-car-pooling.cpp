class Solution {
public:
   static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first){
            return a.second  > b.second; 
        }
        return a.first<b.first;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      vector<pair<int,int>>temp;
        for(vector<int>a:trips){
            temp.push_back({a[1],-a[0]});
            temp.push_back({a[2],a[0]});
        }
        sort(temp.begin(),temp.end(),cmp);
        int res=0;
        for(auto i:temp){
            cout<<i.first<<" "<<i.second<<endl;
           if(i.second < 0){
               res+=abs(i.second);
           }
            else{
                res-=i.second;
            }
            if(res>capacity){
                return false;
            }
        }
        
        return true;
    }
};