
class Solution {
public:
   
    int count=0;
    void paths(TreeNode *root,set<int>m){
       
       
       if(m.find(root->val) != m.end()){
           m.erase(root->val);
       }
        else{
            m.insert(root->val);
        }
        if(!root->left && !root->right){
            if(m.size() <= 1){
                count++;
            }
            if(m.find(root->val) != m.end()){
                m.erase(root->val);
            }
            return ;
        }
       
          
  if(root->left){paths(root->left,m);}
    if(root->right){paths(root->right,m);}
 
}
    int pseudoPalindromicPaths(TreeNode* root) {
         set<int>m;
        if(!root){
            return 0;
        }
        paths(root,m);
        return count;
    }
};