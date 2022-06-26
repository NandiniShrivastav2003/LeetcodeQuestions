class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int inc=0;int dec=0;
        int maxSum=0;
        bool change=false;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1] < arr[i]){
                if(change){
                    inc=0;dec=0;
                    change=false;
                }
                inc++;
            }
            else if(arr[i-1] > arr[i]){
                dec++;
                change=true;
            }
            else{
                inc=0;dec=0;
            }
            if(inc != 0 && dec != 0){
                maxSum=max(maxSum,inc+dec+1);
            }
        }
        return maxSum;
    }
};