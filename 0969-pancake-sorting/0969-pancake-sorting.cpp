class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        if(arr.size() == 1){
            return arr;
        }
        vector<int>res;
        int size=arr.size();
        while(size > 2){
           int maxnum=INT_MIN,maxind=-1;
            for(int i=0;i<size;i++){
                if(arr[i] > maxnum){
                    maxnum=arr[i];
                    maxind=i;
                }
            }
            res.push_back(maxind+1);
            res.push_back(size);
            reverse(arr.begin(),arr.begin()+maxind+1);
            reverse(arr.begin(),arr.begin()+size);
            
            size--;
        }
        if(arr[0] > arr[1]){
            res.push_back(2);
        }
        return res;
    }
};