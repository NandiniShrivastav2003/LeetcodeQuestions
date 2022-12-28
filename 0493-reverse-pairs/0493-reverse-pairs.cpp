class Solution {
public:
    // int merge(vector<int>&nums,int low,int mid,int high){
    //     int cnt=0;
    //     int j=mid+1;
    //     for(int i=low;i<=mid;i++){
    //         while(j<=high && (long)nums[i]>(long)(2*nums[j])){
    //             j++;
    //         }
    //         cnt += (j-(mid+1));
    //     }
    //     vector<int>temp;
    //     int left=low,right=mid+1;
    //     while(left <= mid && right <=high){
    //         if(nums[left] <= nums[right]){
    //             temp.push_back(nums[left++]);
    //         }
    //         else{
    //             temp.push_back(nums[right++]);
    //         }
    //     }
    //     while(left<=mid){
    //         temp.push_back(nums[left++]);
    //     }
    //     while(right <= high){
    //         temp.push_back(nums[right++]);
    //     }
    //     for(int i=low;i<=high;i++){
    //         nums[i]=temp[i-low];
    //     }
    //     return cnt;
    // }
    // int mergeSort(vector<int>nums,int left,int right){
    //     if(left >= right){ 
    //         return 0;
    //     }
    //     int mid=(left+right)/2;
    //      int inv= mergeSort(nums,left,mid);
    //   inv+=  mergeSort(nums,mid+1,right);
    //    inv+= merge(nums,left,mid,right);
    //     return inv;
    // }
    // int reversePairs(vector<int>& nums) {
    //     return mergeSort(nums,0,nums.size()-1);
    // }
    void _merge(vector<int>& nums, int low, int mid, int high, int &reversePairCount) {
    int leftInd = low, rightInd = mid+1, r = rightInd, temp[high-low+1], tempInd = 0, counter = 0;
    // 4 6 8,  1 2 3
    while(leftInd<=mid) {
        while( r<=high && (nums[leftInd] > (long)2*nums[r]) ) counter++, r++;
        reversePairCount+= counter;
        while( rightInd<=high && nums[rightInd]<=nums[leftInd] ) {
            temp[tempInd++] = nums[rightInd++];
        }
        temp[tempInd++] = nums[leftInd++];
    }
    while(rightInd<=high) {
        temp[tempInd++] = nums[rightInd++];
    }
    for(int i=0; i<tempInd; i++) nums[low++] = temp[i];
}

void _mergeSort(vector<int>& nums, int low, int high, int &reversePairCount) {
    if(low < high) {
        int mid = low + (high-low)/2;
        _mergeSort(nums, low, mid, reversePairCount);
        _mergeSort(nums, mid+1, high, reversePairCount);
        _merge(nums, low, mid, high, reversePairCount);
    }
}

int reversePairs(vector<int>& nums) {
    int reversePairCount = 0;
    int sz = nums.size();
    if(sz<=1) return reversePairCount;
    _mergeSort(nums, 0, sz-1, reversePairCount);
    return reversePairCount;
}
};