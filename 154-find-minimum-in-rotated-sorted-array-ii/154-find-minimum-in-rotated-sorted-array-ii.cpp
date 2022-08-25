class Solution {
public:
    int findMin(vector<int>& arr) {
         int i=0;int j=arr.size()-1;
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
              while(i!= mid && arr[i] == arr[mid]){
                i++;
            }
            while(j!= mid && arr[j] == arr[mid]){
                j--;
            }
            if(arr[mid] < ans){
                ans=arr[mid];
            }
          
            if(arr[i] <= arr[mid]){
                ans=min(ans,arr[i]);
                i=mid+1;
            }
            else{
             j=mid-1;
              }

        }
        return ans;
    }
};