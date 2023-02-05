class Solution {
public:
    int partitionDisjoint(vector<int>& arr) {
        int right[arr.size()];
        right[0]=arr[0];
        int n=arr.size();
        int left[arr.size()+1];
         for(int i=1;i<arr.size();i++){
          
            right[i]=max(arr[i],right[i-1]);
        }
         left[arr.size()]=INT_MAX;
        for(int i=arr.size()-1;i>=0;i--){
            left[i]=min(left[i+1],arr[i]);
        }
        int c=0;
          for(int i=0;i<n;i++){
           if(right[i] <= left[i+1]){
              return i+1;
           }
        }
           
        
        return c+1;
    }
};