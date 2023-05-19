class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int time) {
        int n=arr.size();
        int pre[n];
        int suff[n];
       pre[0]=0;
        suff[n-1]=0;
        for(int i=1;i<n;i++){
            if( arr[i-1] >= arr[i]){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=0;
            }
           
        }
       
        for(int i=n-2;i>=0;i--){
            if(arr[i] <= arr[i+1]){
                suff[i]=suff[i+1]+1;
            }
            else{
                suff[i]=0;
            }  
        }
        vector<int>Ans;
        for(int i=time;i+time<n;i++){
            if( pre[i] >= time &&  suff[i] >= time){
                Ans.push_back(i);
            }
        }
        return Ans;
    }
};