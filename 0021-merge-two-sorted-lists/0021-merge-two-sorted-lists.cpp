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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode *res=new ListNode(-1);
		ListNode *newLL=res;
		// head2=head2->next;
		// head1=head1->next;
		while(head1 != NULL && head2 != NULL){
			if(head1->val == head2->val){
res->next=new ListNode(head1->val);
res=res->next;
                res->next=new ListNode(head2->val);
res=res->next;
head1=head1->next;
head2=head2->next;
			}
			else if(head1->val < head2->val){
res->next=new ListNode(head1->val);
res=res->next;
head1=head1->next;

			}
			else{
res->next=new ListNode(head2->val);
res=res->next;
head2=head2->next;
			}
		}
		while(head1 != NULL){
			res->next=new ListNode(head1->val);
res=res->next;
head1=head1->next;
		}
			while(head2 != NULL){
			res->next=new ListNode(head2->val);
res=res->next;
head2=head2->next;
		}
        return newLL->next;
    }
};