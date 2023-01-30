
class Solution {
    int prei=0;
    TreeNode TreeConstruct(int pre[],int in[],int i,int j){
			if(j<i  ){
				return null;
			}
                 int indi=-1;
			TreeNode res=new TreeNode(pre[prei++]);
			for(int k=i;k<=j;k++){
				if(res.val == in[k]){
					indi=k;
					break;
				}
			}
			
			res.left=TreeConstruct(pre,in,i,indi-1);
			res.right=TreeConstruct(pre,in,indi+1,j);
           
			return res;
		}
    public TreeNode buildTree(int[] pre, int[] in) {
        return TreeConstruct(pre,in,0,in.length-1);
    }
}