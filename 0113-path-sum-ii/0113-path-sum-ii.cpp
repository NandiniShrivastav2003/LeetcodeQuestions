class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;
    void allPaths(TreeNode* root, int targetSum,int sum)
    {
        if(root == NULL){
            return ;
        }
        sum+=root->val;
        temp.push_back(root->val);
      
        if(sum == targetSum && root->left == NULL && root->right ==NULL){
            res.push_back(temp);
           
        }
       
        allPaths(root->left,targetSum,sum);
        allPaths(root->right,targetSum,sum);
       
      //  cout<<temp.back()<<endl;
        temp.pop_back();
        
      
        
    }    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        allPaths(root,targetSum,0);
        return res;
    }
};