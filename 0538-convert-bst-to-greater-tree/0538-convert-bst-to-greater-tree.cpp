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
    int maxi=0;
    void greaterBST(TreeNode *root){
        if(root == NULL){
            return ;
        }
        greaterBST(root->right);
        maxi+=root->val;
        root->val = maxi;
        greaterBST(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        greaterBST(root);
        return root;
    }
};