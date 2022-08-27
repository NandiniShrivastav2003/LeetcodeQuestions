class Solution {
public:
    bool check(vector<int>nums,int k,int h){
        long  hours=0;
        for(int x:nums){
            int div=x/k;
            hours+=div;
            if(x % k != 0){
                hours++;
            }
        }
        return hours <=  h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
    int lo=1;
        int hi=piles[piles.size()-1];
        int ans=INT_MAX;
        while(lo <= hi){
           
            int mid=(lo+hi)/2;
         
            if(check(piles,mid,h)){
                ans=min(ans,mid);
                hi=mid-1;
            }
            else{
             lo=mid+1;
            }
            
        }
        return ans;
    }
};