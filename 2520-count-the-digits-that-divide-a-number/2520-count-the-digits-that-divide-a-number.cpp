class Solution {
public:
    int countDigits(int num) {
        int ans=0;
        string temp=to_string(num);
        for(int i=0;i<temp.size();i++){
            if(num % (temp[i]-'0') == 0){
                ans++;
            }
        }
        return ans;
    }
};