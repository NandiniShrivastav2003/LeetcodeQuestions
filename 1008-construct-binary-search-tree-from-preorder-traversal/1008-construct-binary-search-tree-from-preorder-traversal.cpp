class Solution {
public:
    int i=0;
TreeNode *solve(vector<int>& pre,int hi){
     if(i == pre.size() || pre[i] > hi){
            return NULL;
        }
       TreeNode *root=new TreeNode(pre[i++]);
       root->left=solve(pre,root->val);
       root->right=solve(pre,hi);
    return root;
}
        TreeNode* bstFromPreorder(vector<int>& pre) {
       int hi=INT_MAX;
        return solve(pre,hi);
    }
};