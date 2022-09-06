class Solution {
    public TreeNode pruneTree(TreeNode root) {
        return containsOne(root)?root:null;
    }
    public boolean containsOne(TreeNode root){
        if(root == null){
            return false;
        }
        boolean leftone=containsOne(root.left);
         boolean rightone=containsOne(root.right);
        if(!leftone){
            root.left=null;
        }
        if(!rightone){
            root.right=null;
        }
        return root.val == 1 || leftone || rightone;
    }
}