class Solution {
public:
   TreeNode* build(TreeNode *root,int x){
       if(root == NULL){
           return new TreeNode(x);
       }
       
        if(root->val < x){
            TreeNode *temp=new TreeNode(x);
            temp->left=root;
            return temp;
        }
     
           root->right=build(root->right,x);
     
     
       return root;
       
    }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
       return  build(root,val);
       
    }
};