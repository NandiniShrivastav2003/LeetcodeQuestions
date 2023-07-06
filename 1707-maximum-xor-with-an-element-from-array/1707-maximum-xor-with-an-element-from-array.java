
class Solution {
     public static class Node{
        Node zero;
        Node one;


    }
    public static void insert(Node root,int val){
     Node curr=root;
     for(int i=31;i>=0;i--){
         if((val & (1<<i)) == 0){
             if(curr.zero != null){
                 curr=curr.zero;
             }
             else{
                  Node nn=new Node();
                  curr.zero=nn;
                  curr=nn;
             }
         }
         else{
             if(curr.one != null){
                 curr=curr.one;
             }
             else{
                 Node nn=new Node();
                 curr.one=nn;
                 curr=nn;
             }
         }
     }

    }
    public static int getMaxXor(Node root,int val){
        int num=0;
        Node curr=root;
        for(int i=31;i>=0;i--){
            int bit=(val & (1<<i)); //to check whethera bit is 1 or 0.
            if(bit == 0){
            if(curr.one != null){
                num+=(1<<i);
                curr=curr.one;
            }
            else{
                curr=curr.zero;
            }
            }
            else{
          if(curr.zero != null){
              num+=(1<<i);
              curr=curr.zero;
          }
          else{
              curr=curr.one;
          }
            }
        }
        return num;
    }

    public int findMaximumXOR(int[] arr) {
        Node root=new Node();
        for(int val:arr){
            insert(root,val);
        }
        int xor=Integer.MIN_VALUE;
        for(int val:arr){
            xor=Math.max(xor,getMaxXor(root,val));
        }
    return xor;
    }
    public static class Pair{
        int xi;
        int mi;
        int qi;
        Pair(int xi,int mi,int qi){
        this.xi=xi;
        this.mi=mi;
        this.qi=qi;
        }
    }
    public int[] maximizeXor(int[] nums, int[][] qr) {
        //pair with [xi,mi,qi]=>qi = query number
        Arrays.sort(nums);
     Pair []p=new Pair[qr.length];
     for(int i=0;i<p.length;i++){
         p[i]=new Pair(qr[i][0],qr[i][1],i);
     }
     //sort on basis of mi
     Arrays.sort(p,new Comparator<Pair>(){
      public int compare(Pair o1,Pair o2){
         return o1.mi-o2.mi;
      }
     });
        Node root=new Node();
        int []ans=new int [p.length];
        int j=0;
        for(int i=0;i<ans.length;i++){
            while(j<nums.length && nums[j]<=p[i].mi){
                insert(root,nums[j]);
                j++;
            }
            if(j == 0){
                ans[p[i].qi]=-1;
            }
            else{
                ans[p[i].qi]=getMaxXor(root,p[i].xi);
            }
        }
  return ans;
    }
}