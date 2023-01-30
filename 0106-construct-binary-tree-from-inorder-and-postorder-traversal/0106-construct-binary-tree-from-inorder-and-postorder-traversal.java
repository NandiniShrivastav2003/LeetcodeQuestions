
class Solution {
    int ind;
    HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
    public TreeNode build(int []in,int []post,int i,int j){
        if(j<i){
            return null;
        }
        TreeNode res=new TreeNode(post[ind--]);
    
       int temp=map.get(res.val);
       
        res.right=build(in,post,temp+1,j);
        res.left=build(in,post,i,temp-1);
        return res;
    }
    public TreeNode buildTree(int[] in, int[] post) {
        for(int i=0;i<in.length;i++){
            map.put(in[i],i);
        }
        ind=in.length-1;
        return build(in,post,0,in.length-1);
        
        
    }
}