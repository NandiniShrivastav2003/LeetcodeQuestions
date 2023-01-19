class Solution {
public:
    int f=1;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int x=1+height(root->left);
        int y=1+height(root->right);
        if(abs(x-y)>1)
            f=0;
        return max(x,y);
    }
    
    bool isBalanced(TreeNode* root) {
        
        height(root);
        return f;
    }
};