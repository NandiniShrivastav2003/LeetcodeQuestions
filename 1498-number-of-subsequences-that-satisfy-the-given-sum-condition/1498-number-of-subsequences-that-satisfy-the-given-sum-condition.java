class Solution {
    public int numSubseq(int[] nums, int target) {
         Arrays.sort(nums);
        int res=0,mod=1000_000_000+7;
        int pow[]=new int[nums.length+1];
        pow[0]=1;
        for(int i=1;i<=nums.length;i++)
            pow[i]=(pow[i-1]*2)%mod;
      int i=0,j=nums.length-1;
        while(i<=j){
            if(nums[i]+nums[j]<=target) res=(res+pow[j-i++])%mod;
            else j--;
        }
        return res;
    }
}