class Solution {
public:
    int nextGreaterElement(int n) {
        
        string nums=to_string(n);
        int nn=nums.size();
        if(nn == 1){
            return -1;
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
        long intdata;
         stringstream obj;  
     obj << nums; // insert data into obj  
     obj >> intdata;
   
        return intdata > INT_MAX || intdata <= n?-1:intdata;
    }
};