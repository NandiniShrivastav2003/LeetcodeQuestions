class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[]bucket=new boolean[1440];
        for(String timePoint:timePoints){
        String []t=timePoint.split(":");
        int hours=Integer.parseInt(t[0]);
        int mins=Integer.parseInt(t[1]);
        int total=hours*60+mins;
        if(bucket[total]){
            return 0;
        }
        bucket[total]=true;
        }
        int min=Integer.MAX_VALUE,first=-1,prev=-1,curr=-1;
        for(int i=0;i<bucket.length;i++){
            if(bucket[i]){
                if(prev == -1){
                    prev=i;
                    first=i;
                    
                }
                else{
                    curr=i;
                    min=Math.min(min,curr-prev);
                    prev=curr;
                }
            }
        }
        return Math.min(min,1440-curr+first);
    }
}