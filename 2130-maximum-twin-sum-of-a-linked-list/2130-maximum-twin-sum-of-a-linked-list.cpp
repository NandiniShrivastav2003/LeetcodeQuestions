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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
         ListNode *newNode;
        ListNode *prev=NULL;
        while(slow){
           newNode=slow->next;
               slow->next=prev;
            prev=slow;
            slow=newNode;
        }
        int res=0;
        while(prev){
            res=max(res,head->val+prev->val);
            head=head->next;
            prev=prev->next;
        }
        return res;
    }
};