class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
         int res=0;
        for(int i=0;i<points.size();i++){
             unordered_map<long,int>m(points.size());
            for(int j=0;j<points.size();j++){
                if( j == i){
                    continue;
                }
               int dy=points[j][1]-points[i][1];
                int dx=points[j][0]-points[i][0];
                int distance=dx*dx+dy*dy;
                m[distance]++;
            }
        
      
        for(auto &i:m){
            if(i.second > 1){
                res+=i.second*(i.second-1);
            }
        }
        }
        return res;
    }
};