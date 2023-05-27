class Solution {
public:
    TreeNode *getSuccessor(TreeNode *curr){
        curr=curr->right;
        while(curr != NULL && curr->left != NULL ){
            curr=curr->left;
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
                root->right=deleteNode(root->right,curr->val);
                
            }
        }
        return root;
    }
};