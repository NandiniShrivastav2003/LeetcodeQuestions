
class Solution {
public:
     int sum=0;
    void cal(string s){
        int j=0;
      
        for(int i=s.size()-1;i>=0;i--){
            sum+=(s[i]-'0')*pow(2,j++);
        }
       
    }
    void allPath(TreeNode *root,string s){
        if(root == NULL){return ;}
        
        if(root->left == NULL && root->right == NULL ){
           s+=to_string(root->val);
            cal(s);
            return ;
        }
        s+=to_string(root->val);
        
        allPath(root->left,s);
        allPath(root->right,s);
    }
    int sumRootToLeaf(TreeNode* root) {
       
     string s="";
        allPath(root,s);
        return sum;
    }
};