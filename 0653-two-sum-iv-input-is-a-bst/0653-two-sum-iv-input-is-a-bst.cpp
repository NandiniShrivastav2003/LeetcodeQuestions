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
    void pushAll(TreeNode *root){
        while(root != NULL){
            st.push(root);
            root=root->left;
        }
        return ;
    }
    void pushRight(TreeNode *root){
        while(root != NULL){
            st2.push(root);
            root=root->right;
        }
        return ;
    }
      int prev() {
        TreeNode *temp=st2.top();
        st2.pop();
        pushRight(temp->left);
        return temp->val;
    }
    int next() {
        TreeNode *temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
     bool hasNext() {
        return !st.empty();
    }
     stack<TreeNode*>st;
    stack<TreeNode*>st2;
    bool findTarget(TreeNode* root, int k) {
          pushAll(root);
        pushRight(root);
     int i=next(); int j=prev();
        //  cout<<i<<" "<<j<<endl;
        while(i<j){
          
            if(i+j == k){
                return true;
            }
            else if(i+j >k){
             j=prev();
                
            }
            else{
                i=next();
            }
            
        }
        return false;
    }
};