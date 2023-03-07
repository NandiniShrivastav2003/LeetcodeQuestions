class Solution {
public:
    bool check(vector<int>&time,int x,long long mid){
        long long res=0;
        for(int i:time){
           
            res+= mid / i;
            
            
        }
        return res >= x;
    }
    long long minimumTime(vector<int>& time, int x) {
        sort(time.begin(),time.end());
        long long low=time[0];
        long long high=100000000000001;
        long long ans=0;
        while(low <= high){
            long long mid=low+(high-low)/2;
         
            if(check(time,x,mid)){
               
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};