/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy=new ListNode();
        PriorityQueue<ListNode>pq=new PriorityQueue<>(new Comparator<ListNode>(){
            @Override
            public int compare(ListNode o1,ListNode o2){
                return o1.val-o2.val;
            }
        });
        if(lists == null){
            return null;
        }
        for(int i=0;i<lists.length;i++){
           if(lists[i] != null){
               pq.add(lists[i]);
           }
        }
        ListNode temp=dummy;
        while(!pq.isEmpty()){
            ListNode r=pq.poll();
            dummy.next=r;
            dummy=dummy.next;
            if(r.next != null){
              pq.add(r.next);
            }
            
        }
        return temp.next;
    }
}