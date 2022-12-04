class Solution {
public:
    int candy(vector<int>& r) {
    vector<int>left(r.size(),1);
    vector<int>right(r.size(),1);
        
        for(int i=1;i<r.size();i++){
            if(r[i]>r[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        for(int i=r.size()-2;i>=0;i--){
            if(r[i] > r[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        int res=0;
        for(int i=0;i<r.size();i++){
            res+=max(left[i],right[i]);
        }
        return res;
    }
};