class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        ListNode *curr=head;
        int len=0;
        while(temp != NULL){
            len++;
            temp=temp->next;
        }
        len=len/2;
        int i=0;
        while(i<len-1){
            i++;
            curr=curr->next;
        }
        ListNode *prev=NULL;
        ListNode *fast=curr->next;
        while(fast != NULL){
            ListNode*temp=fast->next;
            fast->next=prev;
            prev=fast;
            fast=temp;
        }
        curr->next=prev;
        int sum=INT_MIN;
        i=0;
        temp=head;
        while(i<len){
            //cout<<curr->next->val<<" "<<temp->val<<endl;
            sum=max(sum,(curr->next->val+temp->val));
            temp=temp->next;
            curr=curr->next;
            i++;
            
            
}
        return sum;
    }
};