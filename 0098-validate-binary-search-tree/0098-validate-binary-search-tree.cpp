/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    
public:

    bool isValid(TreeNode *root,long lmin,long rmax){
        if(root == NULL){
            return true;
        }
        if(root->val <= lmin || root->val >= rmax){
            return false;
        }
        bool a=isValid(root->left,lmin,root->val);
        bool b=isValid(root->right,root->val,rmax);
        return a && b;
    }
    bool isValidBST(TreeNode* root) {
        if( (!root->left  && !root->right)){
            return true;
        }
        return isValid(root,LONG_MIN,LONG_MAX);
    }
    
};