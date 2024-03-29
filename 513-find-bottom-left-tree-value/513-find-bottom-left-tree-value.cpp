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
    int res;
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int c=n;
            while(n--){
                TreeNode *curr=q.front();
                if(c-1 == n){
                res=curr->val;
                    
                }
                q.pop();
                if(curr->left){q.push(curr->left);}
                if(curr->right){q.push(curr->right);}
                
            }
        }
return res;
    }
};