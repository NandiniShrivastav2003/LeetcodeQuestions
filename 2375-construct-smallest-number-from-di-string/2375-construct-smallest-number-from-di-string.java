class Solution {
    public String smallestNumber(String pattern) {
        return FormNumber(pattern);
    }
    public static String FormNumber(String s){
        int []ans=new int[s.length()+1];
        int count=0;
        Stack<Integer>st=new Stack<>();
        for(int i=0;i<=s.length();i++){
            if(i == s.length() || s.charAt(i) == 'I'){
                ans[i]=++count;
                while(!st.isEmpty()){
                    ans[st.peek()]=++count;
                    st.pop();
                }
            }
            else{
                st.push(i);
            }
        }
            String str="";
        for(int i=0;i<ans.length;i++){
           str+=ans[i];
        }
             return str;
    }
       
    }
