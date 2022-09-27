class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int c=0;
        for(auto i:mp){
            if(i.second == 1){
                return -1;
            }
            else if(i.second >= 3){
                c+=(i.second)/3;
                if(i.second % 3 == 1 || i.second % 3 == 2){
                    c+=1;
                }
            }
            else{
                c+=1;
            }
        }
        return c;
    }
};
