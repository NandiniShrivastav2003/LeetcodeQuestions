class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        int i=0;
        int j=skill.size()-1;
        bool f=false;
        int temp;
        while(i<j){
            if(f == false){
            temp=(skill[i] + skill[j]);
                ans+=(skill[i]*skill[j]);
                f=true;
                i++;j--;
                }
            else if(temp == skill[i]+skill[j]){
                 ans+=(skill[i]*skill[j]);
                i++;j--;
            }
            else{
                return -1;
            }
           
        }
        return ans;
    }
};