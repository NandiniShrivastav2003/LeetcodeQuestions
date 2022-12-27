class Solution {
public:
    int i=0;

        TreeNode* bstFromPreorder(vector<int>& pre,int hi=INT_MAX) {
        if(i == pre.size() || pre[i] > hi){
            return NULL;
        }
       TreeNode *root=new TreeNode(pre[i++]);
       root->left=bstFromPreorder(pre,root->val);
       root->right=bstFromPreorder(pre,hi);
        return root;
    }
};