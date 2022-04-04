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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1=head;
        ListNode *p2=head;
        ListNode *p3;
        while(--k){
            if(k){p1=p1->next;}
        }
            p3=p1;
            p1=p1->next;
        while(p1){
            p1=p1->next;
            p2=p2->next;
        }
        swap(p3->val,p2->val);
        return head;
    }
};