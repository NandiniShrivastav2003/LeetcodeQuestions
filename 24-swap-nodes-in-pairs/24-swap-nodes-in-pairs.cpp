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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){return head;}
        ListNode* curr=head;
        ListNode * front=curr->next;
        ListNode *res=front;
        while(curr != NULL){
            ListNode *temp=front->next;
            front->next=curr;
            if(temp == NULL){
                curr->next=NULL;
               break;
            }
            ListNode *l;
            if(temp && temp->next){
                l=temp->next;
            }
            else{
                l=temp;
            }
            curr->next=l;
            curr=temp;
            front=l;
        }
        return res;
    }
};