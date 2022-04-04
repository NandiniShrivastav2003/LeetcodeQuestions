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
        ListNode *p3=head;
        int len=0;int c=0;
        while(p3 != NULL){
            len++;
            p3=p3->next;
        }
        len=len-k;
        while(c<k-1 || c<len){
            if(c <k-1)p2=p2->next;
             if(c <len){p1=p1->next;
                         }
            ++c;
            
        }
        swap(p1->val,p2->val);
        return head;
    }
};