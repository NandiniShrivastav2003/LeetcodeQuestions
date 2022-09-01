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
 
    int count=0;
     int temp;
    void preorder(TreeNode *root,int check){
        if(root == NULL){
        return;
        }
//     if(check > root->val){
//         temp=check;
//     }
//     else{
//         temp=root->val;
// }
        int temp=max(check,root->val);
    
        if(temp == root->val){
            count++;
        }
      
      //  prev=root->val;
        preorder(root->left,max(root->val,check));
        preorder(root->right,max(root->val,check));
    }
    int goodNodes(TreeNode* root) {
           // int prev=root->val;
        preorder(root,root->val);
        
        
        return count;
    }
};