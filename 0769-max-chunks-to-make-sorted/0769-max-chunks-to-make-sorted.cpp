class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans[arr.size()];
        ans[0]=0;
        int max_till_i[arr.size()];
        max_till_i[0]=arr[0];
       for(int i=1;i<arr.size();i++){
           ans[i]=i;
           max_till_i[i]=max(arr[i],max_till_i[i-1]);
           
       } 
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(ans[i] == max_till_i[i]){
                count++;
            }
        }
        return count;
    }
};