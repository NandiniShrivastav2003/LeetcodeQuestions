class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        
        for(int i=0;i<nums.size();i++){
           
            for(int j=i+1;j<nums.size();j++){
            
                 string res1="";string res2="";
                res1+=to_string(nums[i]);
                res2+=to_string(nums[j]);
                res2+=to_string(nums[i]);
                res1+=to_string(nums[j]);
                //cout<<res1<<" "<<res2<<endl;
                if(res1 > res2){
                    
                }
                else{
                    swap(nums[i],nums[j]);
                }
                
            }
        }
        string ans="";
        for(int i=0;i<nums.size();i++){
          //  cout<<nums[i];
            ans+=to_string(nums[i]);
        }
        return ans[0] == '0' ? "0":ans;
    }
};