class Solution {
   boolean backtrack(String S, int start, ArrayList <Integer>nums){
       if(S.length() == start){
return nums.size()>2;
       }
int num=0;
       for(int i=start;i<S.length();i++){
           num=(num*10)+(S.charAt(i)-'0');
           if(num < 0 ){
               return false;
           }
           if(nums.size() < 2 || nums.get(nums.size()-1)+nums.get(nums.size()-2 ) == num){
               nums.add(num);
               if(backtrack(S,i+1,nums)){
                   return true;
               }
               nums.remove(nums.size()-1);
           }
           if(i == start && S.charAt(i) == '0'){
               return false;
           }
       }
       return false;

    }
    public List<Integer> splitIntoFibonacci(String num) {
      ArrayList <Integer>nums=new ArrayList<>(); 
          backtrack(num, 0, nums);
        return nums;
        
    }
}