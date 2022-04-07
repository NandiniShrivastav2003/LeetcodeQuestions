class Solution {
public:
    TreeNode *getSuccessor(TreeNode *curr){
        curr=curr->left;
        while(curr != NULL && curr->right != NULL ){
            curr=curr->right;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){return NULL;}
        if(root->val > key){root->left=deleteNode(root->left,key);}
        else if(root->val < key){root->right=deleteNode(root->right,key);}
        else{
            if(root->left == NULL){
                TreeNode *temp=root->right;
                delete(root);
                return temp;
            }
           else if(root->right == NULL){
                TreeNode *temp=root->left;
                delete(root);
                return temp;
            }
            else{
                TreeNode *curr=getSuccessor(root);
                root->val = curr->val;
                root->left=deleteNode(root->left,curr->val);
                
            }
        }
        return root;
    }
};