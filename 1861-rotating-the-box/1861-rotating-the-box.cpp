class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>res;
        for(int i=0;i<n;i++){
            vector<char>temp;
            for(int j=0;j<m;j++){
                temp.push_back(box[j][i]);
            }
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        for(int i=0;i<res[0].size();i++){
           int j=res.size()-1;
            int stone=0;
            int x=j,y=i;
            while(j >=0 ){
                if(res[j][i] == '.'){
                   
                  
                   
                }
                if(res[j][i] == '*'){
                   
                 x=j-1;
                
                }
               if(res[j][i] == '#'){
                    res[x][y]='#';
                   if(x != j ){
                    res[j][i]='.';
                   }
                  x--;
                   
                }
                j--;
               
            }
        }
        return res;
        
    }
};