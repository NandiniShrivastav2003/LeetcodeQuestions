class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int i=0;
        int n = nums.size();
        while(i<n)
        {
			int correctIdx = nums[i]; //where this element should be in sorted array
            if(correctIdx<n && correctIdx != i) //if not already at correct position and correct position < n
            {
                swap(nums[i],nums[correctIdx]); //put current element at correct position
            } 
			else
				i++; // move to next index
        }
        for(int i=0;i<n; i++)
            if(nums[i]!=i)
                return i;
        return n;
    }
};