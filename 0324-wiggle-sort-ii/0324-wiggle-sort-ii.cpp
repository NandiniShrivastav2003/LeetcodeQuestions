class Solution {
public:
    void wiggleSort(vector<int>& nums) {
         vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int j=temp.size()-1;
         for(int i=1;i<nums.size();i+=2){
        nums[i]=temp[j];
             j--;
       }
       //intution-we sort the array and fill half larger elements at odd index since
        //we want odd index elements to be larger than even indexed elements then we fill even indexed elements with value from arr[mid-1 ] to 0.
        
        //note -- we can't fill elements in even indexed from 0 to arr[mid-1] as it will result in failed test case in -[1,3,2,2,3,1] -> [1,3,1,3,2,2] which is false but acc to above method:[2,3,1,3,1,2] (arr[mid-1] to 0);
        for(int i=0;i<nums.size();i+=2){
            nums[i]=temp[j];
            j--;
        }
        
        return ;
    }
};