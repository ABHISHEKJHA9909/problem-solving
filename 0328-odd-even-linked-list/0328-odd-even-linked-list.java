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
    public ListNode oddEvenList(ListNode head) {
        if(head==null || head.next==null)
            return head;
        
        ListNode o=head;
        ListNode e=head.next;
        ListNode e_start=e;
        
        ListNode node=head.next.next;
        Boolean parity=true;
        
        while(node!=null){
            if(parity){
                o.next=node;
                o=o.next;
            }
            else{
                e.next=node;
                e=e.next;
            }
            node=node.next;
            parity=!parity;
        }
        
        o.next=e_start;
        e.next=null;
        
        return head;
    }
}