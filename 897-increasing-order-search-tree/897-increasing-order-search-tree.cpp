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
    vector<int>res;
    void pre(TreeNode *root){
        if(root == NULL){
            return;
        }
        pre(root->left);
        res.push_back(root->val);
        pre(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        pre(root);
        TreeNode *out=new TreeNode(res[0]);
        TreeNode *fin=out;
        for(int i=1;i<res.size();i++){
            out->right=new TreeNode(res[i]);
            out=out->right;
        }
        return fin;
    }
};