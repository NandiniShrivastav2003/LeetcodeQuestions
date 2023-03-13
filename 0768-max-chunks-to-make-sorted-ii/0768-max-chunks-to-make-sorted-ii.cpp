class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int right[arr.size()];
        right[0]=arr[0];
        int left[arr.size()+1];
        int n=arr.size();
        int ans=0;
        for(int i=1;i<arr.size();i++){
           
            right[i]=max(arr[i],right[i-1]);
        }
        left[arr.size()]=INT_MAX;
        for(int i=arr.size()-1;i>=0;i--){
            left[i]=min(left[i+1],arr[i]);
        }
      
        for(int i=0;i<n;i++){
           if(right[i] <= left[i+1]){
               ans++;
           }
        }
       
        return ans;
    }
};