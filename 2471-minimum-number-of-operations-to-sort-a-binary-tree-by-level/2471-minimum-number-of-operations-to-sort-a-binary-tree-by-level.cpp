
class Solution {
public:
    int minswaps(vector<int>&res){
        vector<pair<int,int>>temp;
        int n=res.size();
        int ans=0;
        vector<int>vis(n,false);
        for(int i=0;i<n;i++){
            temp.push_back({res[i],i});
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            if(vis[i] == true || temp[i].second == i){
                continue;
            }
            int j=i;
            int count=0;
            while(vis[j] == false){
                vis[j]=true;
                count++;
                j=temp[j].second;
            }
            ans+=(count-1);
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
      vector<int>res;
        int ans=0;
        queue <TreeNode*>q;
        q.push(root);
        if(root == NULL)
            return 0;
        while(q.empty() == false){
              vector<int>res;
     
            int count=q.size();
            for(int i=0;i<count;i++){
                  TreeNode *curr=q.front();
            q.pop();
               res.push_back(curr->val);
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
          ans+=minswaps(res);
         res.clear();
            }    
        
        return ans; 
    }
};