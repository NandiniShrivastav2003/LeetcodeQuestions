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
//     int ans=-1;
//     int height(TreeNode *root){
//         if(root == NULL){
//             return 0;
//         }
//        int a= height(root->left);
//         int b=height(root->right);
     
//      return max(a,b)+1;
      
//     }
    bool isCompleteTree(TreeNode* root) {
        // int h=height(root);
        //cout<<h<<endl;
    queue<TreeNode*>q;
        
        q.push(root);
        bool f=false;
      
        while(!q.empty()){
            
//             int lh=pow(2,l);
//             int size=q.size();
//              if(lh != size && l != h-1){
                
//              return false;
//          }
            //while(size>0){
                //size=size-1;
               TreeNode *temp=q.front();
            q.pop();
            if(temp == NULL){
                f=true;
            }
//                 if(temp->left == NULL && temp->right != NULL){
//                     return false;
//                 }
                
//                 if(temp->right == NULL && size > 0 && l != h-1) {
//                     cout<<size<<" "<<temp->val<<" "<<l<<endl;
//                     return false;
//                 }
               else{
                   if(f){
                       return false;
                   }
                    q.push(temp->left);
                
                
                    q.push(temp->right);
               }
            }
            
        
       return true;
    }
};