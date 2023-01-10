/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*best approach--
    traverse the two LL and if one of the two nodes get null then point it to the head of other ll.this will make them to come at the same point in ll and we traverse to get node where address of both lists are same ,otherwise null.
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;
        if(a == NULL || b == NULL){
            return NULL;
        }
        while(a != b){
             if(a == b){
                return a;
            }
            if(a == NULL){
                a=headB;
                
            }
            else{
                a=a->next;
            }
            if(b == NULL){
                b=headA;
                
            }
            else{
                b=b->next;
            }
           
            
        }
        return a;
        
    }
};