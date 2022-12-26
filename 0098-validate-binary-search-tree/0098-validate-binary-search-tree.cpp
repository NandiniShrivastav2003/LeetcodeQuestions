class Solution {
public:
    bool validate(TreeNode *root,long mn,long mx){
         if(root == NULL){
         return true;
         }   
        if(mn>=root->val || root->val>=mx){
            return false;
        }
        bool a=validate(root->left,mn,root->val);
        bool b=validate(root->right,root->val,mx);
        return a && b;
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root ->left && !root->right){
            return true;
        }
    return validate(root,LONG_MIN,LONG_MAX);
    }
};