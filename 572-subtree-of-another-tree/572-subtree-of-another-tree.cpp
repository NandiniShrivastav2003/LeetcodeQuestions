
class Solution {
public:
    vector<TreeNode*>res;
    bool check(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){return true;}
        if(!root && subRoot || root && !subRoot){return false;}
        if(root->val != subRoot->val){
            return false;
        }
        bool a=check(root->left,subRoot->left);
        bool b=check(root->right,subRoot->right);
       
    return a && b;
    }
    void pre(TreeNode* root, TreeNode* subRoot){
        if(root == NULL){
            return ;
        }
        pre(root->left,subRoot);
        pre(root->right,subRoot);
        if(root->val == subRoot->val){
            res.push_back(root);
        
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
         pre(root,subRoot);
        for(int i=0;i<res.size();i++){
           if (check(res[i],subRoot)){
               return true;
           }
        }
        return false;
    }
};