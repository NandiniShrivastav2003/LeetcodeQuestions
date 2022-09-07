class Solution {
public:
   
  string preorder(TreeNode *root){
        
        string res=to_string(root->val);
        if(root -> left){
            res += "(" + preorder(root->left) + ")";
        }
      if(root -> right){
          if(!root->left){
             res+= "()";
          }
       res+= "(" + preorder(root->right) + ")";
      }
       return res;
    }
    string tree2str(TreeNode* root) {
        
        return  preorder(root);
    }
};