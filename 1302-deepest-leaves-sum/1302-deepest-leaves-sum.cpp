class Solution {
public:
       int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
           int ans=0;
        while(q.size() > 0){
            int n=q.size();
            ans=0;
            while(n--){
                TreeNode *curr=q.front();
                q.pop();
              ans+=(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                 
            }
        }
        
        return ans;
    }
};