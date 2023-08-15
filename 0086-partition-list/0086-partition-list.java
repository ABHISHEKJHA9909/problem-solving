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
    public ListNode partition(ListNode head, int x) {
        ListNode dummy=new ListNode(-400);
        dummy.next=head;
        
        ListNode l=dummy;
        
        while(l.next!=null && l.next.val<x)
            l=l.next;
        
        ListNode r=l;
        
        while(r.next!=null){
            if(r.next.val>=x)
                r=r.next;
            else{
                //node insert between
                ListNode temp=r.next;
                r.next=r.next.next;
                temp.next=l.next;
                l.next=temp;
                
                l=l.next;
            }
        }
        
        return dummy.next;
    }
}