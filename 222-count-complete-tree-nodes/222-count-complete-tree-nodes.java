class Solution {
    public int countNodes(TreeNode root) {
        if(root == null){
            return 0;
            
        }
        int lh=1;int rh=1;
        TreeNode l=root.left;TreeNode r=root.right;
        while(l != null){
            lh++;
            l=l.left;
        }
        while(r != null){
            rh++;
            r=r.right;
        }
        if(lh == rh){
            return (int)(Math.pow(2, lh)-1);
          
        }
          return 1+ countNodes(root.left)+countNodes(root.right);
        
    }
}