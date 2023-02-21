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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode curr=head;
        
        for(int i=0;i<k-1;i++){
            curr=curr.next;
        }
        
        ListNode beg=curr;
        ListNode newcurr=head;
        
        while(curr.next!=null){
            curr=curr.next;
            newcurr=newcurr.next;
        }
        int temp=beg.val;
        beg.val=newcurr.val;
        newcurr.val=temp;
        
        return head;
        
    }
}