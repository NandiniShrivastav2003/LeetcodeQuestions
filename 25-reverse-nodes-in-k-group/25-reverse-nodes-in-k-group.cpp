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
    int lengthOfLL(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    bool isFirstPass = true;
    ListNode *res;
    int len = lengthOfLL(head);
    int c2 = len / k;
       ListNode *prevFirst=NULL;
        ListNode *prev=
            NULL;
     ListNode *curr = head;
   
    while (c2 > 0)
    {
        int count = k;
         ListNode* first=curr;
       prev = NULL;
       
 
        while (curr != NULL && count > 0)
        {
           ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            --count;
             
           
        }
        if (isFirstPass)
        {
            isFirstPass = false;
            res = prev;
        }

        else{
            prevFirst->next=prev;
        }
        prevFirst=first;
        --c2;
    }
    if(curr != NULL){
     prevFirst->next=curr;
    }
    return res;
}
   
};