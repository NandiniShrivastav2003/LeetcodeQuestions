class Solution {
public:
    int minAdj(string str,string ans){
       int i=0;
        int j=0;
        int res=0;
        while(i<ans.size()){
            int j=i;
            while(str[j] !=  ans[i]){
                j+=1;
            }
            while(j > i){
                swap(str[j],str[j-1]);
                res++;
                j--;
            }
            i++;
        }
        return res;
    }
    int getMinSwaps(string nums, int k) {
        string temp=nums;
        while(k--){
            int nn=nums.size();
        if(nn == 1){
           return 0;
        }
        int idx=nn-2;
        if(idx >= 0){
            while(idx > 0 && nums[idx+1] <= nums[idx]){
                idx--;
            }
        }
       for(int i=nn-1;i>=0;i--){
           if(nums[i] > nums[idx]){
               swap(nums[i],nums[idx]);
               break;
           }
       }
        reverse(nums.begin()+idx+1,nums.end());
        }
        return minAdj(nums,temp);
    }
};