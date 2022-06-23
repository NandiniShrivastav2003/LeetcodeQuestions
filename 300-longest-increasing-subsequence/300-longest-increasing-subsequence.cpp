class Solution {
public:
    //O(nlogn) solution using binary search and using ceil find function
    int findceil(int tail[],int l,int r,int x){
        while(r>l){
            int m=l+(r-l)/2;
            if(tail[m] >= x){
                r=m;
            }
            else{
                
                l=m+1;
            }
            
        }
        return r;
    }
    int lengthOfLIS(vector<int>& nums) {
        int tail[nums.size()];
        int len=1;
        tail[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] > tail[len-1]){
                tail[len]=nums[i];
                len++;
            }
            else{
                int c=findceil(tail,0,len-1,nums[i]);
                tail[c]=nums[i];
            }
        }
        return len;
    }
};