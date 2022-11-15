class Solution {
    public int maximumSum(int[] arr) {
        int[]first=new int[arr.length];
        int []second=new int[arr.length];
        int ans=arr[0];
        first[0]=arr[0];
        for(int i=1;i<arr.length;i++){
            first[i]=Math.max(arr[i],first[i-1]+arr[i]);
            ans=Math.max(ans,first[i]);
        }
        second[arr.length-1]=arr[arr.length-1];
        for(int i=arr.length-2;i>=0;i--){
            second[i]=Math.max(arr[i],second[i+1]+arr[i]);
        }
        for(int i=1;i<arr.length-1;i++){
            ans=Math.max(ans,first[i-1]+second[i+1]);
        }
        return ans;
    }
}