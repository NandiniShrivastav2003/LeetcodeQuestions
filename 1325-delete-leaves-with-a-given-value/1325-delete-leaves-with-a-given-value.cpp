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
    TreeNode *removenodes(TreeNode *root,int x,TreeNode *prev){
        if(root == NULL){
            return NULL;
        }
       
        TreeNode *l=removenodes(root->left,x,root);
        TreeNode *r=removenodes(root->right,x,root);
         if(l == NULL && r == NULL && root->val == x) {
             return NULL;
         }
        root->left=l;
        root->right=r;
            
    return root;
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return removenodes(root,target,NULL);
    }
};