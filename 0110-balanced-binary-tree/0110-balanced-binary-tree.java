/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
     public class DiaPair{
        int ht=-1;
       boolean hasBal=true;
    }
    public DiaPair TreeBal(TreeNode root){
     if(root == null){
            return new DiaPair(); 
        }
        DiaPair ldp=TreeBal(root.left);
        DiaPair rdp=TreeBal(root.right);
        DiaPair sdp=new DiaPair();
        sdp.ht=Math.max(ldp.ht,rdp.ht)+1;
        sdp.hasBal=Math.abs(ldp.ht-rdp.ht) <= 1 && (ldp.hasBal) && (rdp.hasBal);
        return sdp;
    }
    public boolean isBalanced(TreeNode root) {
        return TreeBal(root).hasBal;
       
    }
}