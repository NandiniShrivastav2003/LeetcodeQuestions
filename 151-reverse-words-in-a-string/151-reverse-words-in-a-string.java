class Solution {
    public String reverseWords(String s) {
       s=s.trim();
        String ans="";
        String [] arr=s.split("\s+");
        //used for splitting the words with one or more spaces.
        for(int i=arr.length-1;i>=0;i--){
            ans+=arr[i]+" ";
        }
        return ans.trim();
    }
}