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
    void sumans(TreeNode *root,int sum){
        if(root == NULL){
            return ;
        }
        
        if(!root->left && !root->right){
           
            ans+=(sum*10+root->val);
            return ;
        }
        sumans(root->left,sum*10+(root->val));
        sumans(root->right,sum*10+(root->val));
    }
    int sumNumbers(TreeNode* root) {
      sumans(root,0); 
        return ans;
    }
};