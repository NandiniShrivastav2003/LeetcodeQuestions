class Solution {
      
    public List<Integer> lexicalOrder(int n) {
        ArrayList<Integer> arrli = new ArrayList<Integer>();
        for(int i=1;i<=9;i++) {
            lexo(n, Integer.toString(i),arrli);
        }
        return  arrli;
    }
    public static void lexo(int b,String res,List<Integer>arrli){
        if(Integer.parseInt(res) > b){

            return ;
        }
arrli.add(Integer.parseInt(res));
            //System.out.println(res);

        for(int i=0;i<=9;i++) {
            lexo(b,res+Integer.toString(i),arrli);

        }
}
}