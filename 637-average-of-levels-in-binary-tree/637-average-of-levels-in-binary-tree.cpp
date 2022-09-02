
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
         vector<double>res;
        queue <TreeNode*>q;
        res.push_back(root->val);
        q.push(root);
        int c=0;
        double sum=0;
        while(q.empty() == false){
              vector<double>res1;
   
            int count=q.size();
            for(int i=0;i<count;i++){
                  TreeNode *curr=q.front();
            q.pop();   
                if(curr->left != NULL){
                    q.push(curr->left);
                    sum+=curr->left->val;
                    c++;
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                    sum+=curr->right->val;
                    c++;
                }
                }
                if(c!=0){
                res.push_back(sum*1.0/c);
                }c=0;
                sum=0;
             
            }   
        
            return res;
    }
};