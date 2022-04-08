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
    void inorder(TreeNode *root){
        if(root == NULL){return ;}
       
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
    
        inorder(root);
        int o=INT_MAX;
        for(int i=0;i<res.size()-1;i++){
            
                o=min(o,(res[i+1]-res[i]));
            
        }
        return o;
    }
};