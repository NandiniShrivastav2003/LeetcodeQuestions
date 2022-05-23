
class Solution {
public:
    bool check(TreeNode* root,long mn,long mx){
        if(root == NULL){
            return true;
        }
        if((root->val) <= mn || (root->val) >= mx){
            return false;
        }
        
        bool a=check(root->left,mn,root->val);
        bool b=check(root->right,root->val,mx);
    return a && b;
    }
    bool isValidBST(TreeNode* root) {
       if( check(root,LONG_MIN,LONG_MAX)){
           return true;
       }
        return false;
        
    }
};