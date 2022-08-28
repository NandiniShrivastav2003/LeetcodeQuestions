/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int sizeLL(ListNode *head){
        ListNode *temp=head;
        int size=0;
        while(temp != NULL){
            temp=temp->next;
            size++;
        }
        return size;
    }
    void reorderList(ListNode* head) {
      int size=sizeLL(head);
        stack<ListNode*>st;
        ListNode *temp=head;
        int s=size%2 == 0?size/2:size/2+1;
        for(int i=1;i<=s;i++){
            temp=temp->next;
        }
        while(temp != NULL){
            st.push(temp);
            temp=temp->next;
        }
        ListNode*first=head;
        ListNode* second;
      while(!st.empty()){
            second=first->next;
            first->next=st.top();
            first=first->next;
            first->next=second;
            first=first->next;
            st.pop();
        }
        first->next=NULL;
    }
};