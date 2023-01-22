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
    int ans=INT_MAX;
    TreeNode *prev=NULL;
  void getMin(TreeNode *root){
        if(root == NULL){
            return ;
        }
        getMin(root->left);
      if(prev){
           cout<<root->val<<" "<<prev->val<<endl;
       ans=min(ans,abs(prev->val-root->val));
      }
    prev=root;
      
        getMin(root->right);
      
    }
    int getMinimumDifference(TreeNode* root) {
       
         getMin(root);
        return ans;
    }
};