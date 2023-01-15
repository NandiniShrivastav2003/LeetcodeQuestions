class Solution {
public:
    int maxConsecutive(string nums,char ch,int k){
        int j=0;
        int ans=0;
        int i=0;
        int temp=0;
        while(i<nums.size()){
            if(nums[i] != ch){
                temp++;
            }
           
            while(temp > k){
                
                if(nums[j] != ch){
                    temp--;
                }
                j++;
            }
            ans=max(ans,i-j+1);  
             i++;
        }
        ans=max(ans,j-i+1);
        return ans;
        
    }
    int maxConsecutiveAnswers(string nums, int k) {
        return max(maxConsecutive(nums,'T',k),maxConsecutive(nums,'F',k)); 
    }
};