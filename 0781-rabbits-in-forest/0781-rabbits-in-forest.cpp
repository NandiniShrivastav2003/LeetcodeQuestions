class Solution {
public:
    int numRabbits(vector<int>& arr) {
        map<int,int>m;
        for(int i:arr){
            m[i]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.first == 0){
                ans+=i.second;
            }
            else{
                int a=i.first;
                int b=i.second;
                ans+=(b/(a+1))*(a+1);
                if(b%(a+1) != 0){
                    ans+=(a+1);
                }
            }
        }
        return ans;
        
    }
};