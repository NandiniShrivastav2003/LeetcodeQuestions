class Solution {
public:
     bool findPath(TreeNode *root,vector<TreeNode*>&p,int n){
      if(root == NULL){
          return false;
      }
      p.push_back(root);
      if(root->val == n){
          return true;
      }
      if(findPath(root->left,p,n) ||findPath(root->right,p,n)){
          return true;
      }
      p.pop_back();
      return false;
  }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>k1;
        vector<TreeNode*>k2;
        if(findPath(root,k1,p->val) == false || findPath(root,k2,q->val) == false){
            return NULL;
        }
        TreeNode* res;       
        for(int i=0;i<=k1.size()-1 && i<=k2.size()-1;i++)
        {
            if(k1[i] == k2[i]){
               res=k1[i];
            }
        }
      
        return res;
    }
};