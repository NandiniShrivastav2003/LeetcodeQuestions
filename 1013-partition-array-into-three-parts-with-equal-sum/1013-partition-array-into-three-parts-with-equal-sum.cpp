class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int k=sum/3;
        if(sum % 3 != 0){
            return false;
        }
        int temp=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            temp+=arr[i];
             if(temp == k){
                ans++;
                temp=0;
                 if(ans == 3){
                     return true;
                 }
            }
            
        }
        return (ans==3  || (k == 0 && ans>=3));
    }
};