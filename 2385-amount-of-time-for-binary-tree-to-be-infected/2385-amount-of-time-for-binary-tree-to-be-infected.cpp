
class Solution {
public:
    TreeNode *createParentMapping(TreeNode *root, int target, map<TreeNode *, TreeNode *> &NodeToParent)

{

    TreeNode *result = NULL;

    queue<TreeNode *> q;

    q.push(root);

    NodeToParent[root] = NULL;

    while (!q.empty())

    {

        TreeNode *front = q.front();

        q.pop();

 

        if (front->val == target)

        {

            result = front;

        }

 

        if (front->left)

        {

            NodeToParent[front->left] = front;

            q.push(front->left);

        }

 

        if (front->right)

        {

            NodeToParent[front->right] = front;

            q.push(front->right);

        }

    }

    return result;

}

int burnTree(TreeNode *targetNode, map<TreeNode *, TreeNode *> &NodetoParent)

{

    map<TreeNode *, bool> visited;

    queue<TreeNode *> q;

 

    q.push(targetNode);

    visited[targetNode] = true;

 

    int ans = 0;

    while (!q.empty())

    {   

 

        bool flag = 0;

        int size = q.size();

        for (int i = 0; i < size; i++)

        {

            // process every neighbouring node

            TreeNode *front = q.front();

            q.pop();

 

            if (front->left && !visited[front->left])

            {   

                flag = 1;

                q.push(front->left);

                visited[front->left] = true;

            }

            if (front->right && !visited[front->right])

            {

                flag =1;

                q.push(front->right);

                visited[front->right] = true;

            }

            if (NodetoParent[front] && !visited[NodetoParent[front]])

            {

                flag = 1;

                q.push(NodetoParent[front]);

                visited[NodetoParent[front]] = true;

            }

        }

        if(flag == true){

            ans++;

        }

    }

    return ans;

}
    int amountOfTime(TreeNode* root, int start) {
         map<TreeNode *, TreeNode *> NodeToParent;

    TreeNode *targetNode = createParentMapping(root, start, NodeToParent);

 

    int ans = burnTree(targetNode, NodeToParent);

    return ans;
    }
};