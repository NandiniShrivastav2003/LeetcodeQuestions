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
    int tilt=0;
int cal(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int sum1 = cal(root->left);
    int sum2 = cal(root->right);
tilt+=abs(sum1-sum2);
  
    return sum1+sum2+root->val;
}
    int findTilt(TreeNode* root) {
        cal(root);
        return tilt;
    }
};