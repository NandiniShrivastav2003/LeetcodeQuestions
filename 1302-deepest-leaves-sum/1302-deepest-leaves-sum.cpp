class Solution {
public:
       int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        vector<int>temp;
        while(q.size() > 0){
            int n=q.size();
            while(n--){
                TreeNode *curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                 
            }
            res.push_back(temp);
            temp.clear();
           
        }
        int ans=0;
          
       int i=res.size()-1;
        for(int j=0;j<res[i].size();j++){
           ans+=res[i][j];
        }
           // cout<<endl;
        
        return ans;
    }
};