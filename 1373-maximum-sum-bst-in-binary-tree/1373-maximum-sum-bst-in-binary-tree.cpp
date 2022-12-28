class NodeValue{
    public:
     int maxNode,minNode,sum;
    bool isbst;
    NodeValue(int minNode,int maxNode,int sum,bool isbst){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->sum=sum;
        this->isbst=true;
    }
};
class Solution {
private:
    int fin=0;
   NodeValue largestbst(TreeNode *root){
       if(!root){
           return NodeValue(INT_MAX,INT_MIN,0,true);
       }
       auto left=largestbst(root->left);
       auto right=largestbst(root->right);
       if(left.isbst && right.isbst && left.maxNode< root->val && root->val < right.minNode){
           int res=root->val+left.sum+right.sum;
           fin=max(fin,res);
           return NodeValue(min(root->val,left.minNode),max(root->val,right.maxNode), res,true );
       }
       return NodeValue(INT_MIN,INT_MAX,max(left.sum,right.sum),false);
   }
    public:
    int maxSumBST(TreeNode* root) {
        NodeValue x=largestbst(root);
        return fin;
    }
};