/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    //we can use slow and fast pointers to run by 3,4,5..but diff is that greater than > 2 it can take more rotations.
    public boolean hasCycle(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;
        while(fast != null && slow != null && fast.next != null){
           
            slow=slow.next;
            
           
            fast=fast.next.next;
            
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
}