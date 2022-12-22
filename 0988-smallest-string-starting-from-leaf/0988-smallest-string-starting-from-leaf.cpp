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
      int ans=0;
    vector<string>res;
    void sumNode(TreeNode *root,string sum,unordered_map<int,char>mp){
        if(root == NULL){
            return ;
        }
        if(!root->left && !root->right){
            sum+=mp[root->val];
            reverse(sum.begin(),sum.end());
           res.push_back(sum);
            return ;
        }

        sumNode(root->left,sum+mp[root->val],mp);
        sumNode(root->right,sum+mp[root->val],mp);
    }
    string smallestFromLeaf(TreeNode* root) {
        unordered_map<int,char>mp;
        char ch='a';
        for(int i=0;i<=25;i++){
            mp[i]=ch;
            ch++;
        }
        sumNode(root,"",mp);
        sort(res.begin(),res.end());
        return res[0];
    }
};