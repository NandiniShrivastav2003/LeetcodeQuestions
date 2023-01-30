class Solution {
    //whenever we want O(N) Time complexity we will maintain a pair of height and diameter.to visit every node only once.
    public class DiaPair{
        int ht=-1;
        int d=0;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        return diameter(root).d;
    }
    public DiaPair diameter(TreeNode root){
        if(root == null){
            return new DiaPair(); 
        }
        DiaPair ldp=diameter(root.left);
        DiaPair rdp=diameter(root.right);
        DiaPair sdp=new DiaPair();
        int sd=ldp.ht+rdp.ht+2;
        sdp.d=Math.max(ldp.d,Math.max(rdp.d,sd));
        sdp.ht=Math.max(ldp.ht,rdp.ht)+1;
        return sdp;
    }
}