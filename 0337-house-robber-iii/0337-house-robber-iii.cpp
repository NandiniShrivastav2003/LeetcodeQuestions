
class Solution {
   
    struct Pair{
        int take;
        int ntake;
       
    };
public:
    
    Pair maxRob(TreeNode *root){
        if(root == NULL){
            return {0,0};
        }
        Pair p1= maxRob(root->left);
        Pair p2= maxRob(root->right);
          int a=p1.ntake+p2.ntake+root->val;
        int b=max(p1.take,p1.ntake)+max(p2.take,p2.ntake);
        return {a,b};
    }
    int rob(TreeNode* root) {
        
        Pair p=maxRob(root);
        return max(p.take,p.ntake);
    }
};