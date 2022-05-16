class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){return NULL;}
        unordered_map<Node*,Node*>mp;
        for(Node *curr=head;curr != NULL ;curr=curr->next){
            mp[curr]=new Node(curr->val);
        }
        bool isFirst=true;
          Node *clonenode;
        Node *res;
        for(Node *curr=head;curr!= NULL ;curr=curr->next){
            
            clonenode=mp[curr];
            if(isFirst){isFirst=false;res=clonenode;}
            clonenode->next=mp[curr->next];
            clonenode->random=mp[curr->random];
        }
        return res;
    }
};