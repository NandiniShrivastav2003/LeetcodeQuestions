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
    int minCameraCover(TreeNode* root) {
       int c=camera(root);
        if(c == -1){
            count++;
        }
        return count;
    } 
    int camera(TreeNode *root){
     if(root == NULL){
            return 1;
        }
       int left= camera(root->left);
       int right=camera(root->right);
    if(left == -1 || right == -1 ){
          count++;
          return 2;
        }
        else if(left == 1 && right == 1){
          return -1;
        }
        
         return 1;
        
    }
};