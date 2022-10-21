class Solution {
    ArrayList<String> list=new ArrayList<String>();
    public void HappyCombo(int n, String s, String temp){
        if(temp.length() > n){
            return ;
        }
        if(temp.length()-2 >=0 && temp.charAt(temp.length()-2) == temp.charAt(temp.length()-1)){
            return ;
        }
        if(temp.length() == n){
         list.add(temp);
            //System.out.println(temp);
            return ;
        }

        for(int i=0;i<s.length();i++){
            HappyCombo(n,s,temp+s.charAt(i));
        }
    }
    public String getHappyString(int n, int k) {
         String s="abc";
          HappyCombo(n,s,"");
        Collections.sort(list);   
        if(list.size() < k){
            return "";
        }
        
            return list.get(k-1);
        
        
    }
}