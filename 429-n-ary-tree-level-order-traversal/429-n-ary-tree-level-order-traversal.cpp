/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>>ans;
        vector<int>temp;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node* p=q.front();
                q.pop();
                temp.push_back(p->val);
                for(Node* c:p->children){
                    q.push(c);
                }
                
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};