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
     TreeNode *a;
    TreeNode *b;
    TreeNode *prev=NULL;
    void inorder(TreeNode *root){
        if(root == NULL){
            return ;
        }
        inorder(root->left);
        if(prev && prev->val > root->val){
            if(a == NULL){
            a=prev;
            }
            b=root;
        }
        prev=root;
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root == NULL){
            return ;
        }
            
        
        inorder(root);
        swap(a->val,b->val);
    }
};