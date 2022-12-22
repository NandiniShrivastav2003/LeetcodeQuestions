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
      int ans=0;
    vector<string>res;
    void sumNode(TreeNode *root,string sum){
        if(root == NULL){
            return ;
        }
        if(!root->left && !root->right){
            sum+=to_string(root->val);
           res.push_back(sum);
            return ;
        }

        sumNode(root->left,sum+to_string(root->val)+"->");
        sumNode(root->right,sum+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        sumNode(root,"");
        return res;
    }
};