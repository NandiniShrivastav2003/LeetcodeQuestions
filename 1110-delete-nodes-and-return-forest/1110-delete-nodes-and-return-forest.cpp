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
    vector<TreeNode*>ans;
    void search(TreeNode *&root,set<int>s){
        if(root == NULL){
            return ;
        }
        
        search(root->left,s);
        search(root->right,s);
        if(s.find(root->val) != s.end()){
         if(root->left){
             
             ans.push_back(root->left);
             
         }   
            if(root->right){
                
                ans.push_back(root->right);
                   
            }
          root=NULL;
           delete(root);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>s(to_delete.begin(),to_delete.end());
       
            search(root,s);
        
        if(root && s.find(root->val) == s.end() ){
        ans.push_back(root);
        }
        return ans;
        
    }
};