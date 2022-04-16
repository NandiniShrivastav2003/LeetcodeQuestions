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
        if(head==NULL || head->next==NULL){return head;}
        
        ListNode *slow=head;
        ListNode *fast=slow->next;
        ListNode *out=fast;
        while(fast != NULL){
            ListNode *l=slow;
            ListNode *temp=fast->next;
            fast->next=slow;
            slow=temp;
           if(slow && slow->next != NULL){ fast=slow->next;}
            else{
            fast=slow;
            }
            l->next=fast;
          
        }
        return out;
    }
};