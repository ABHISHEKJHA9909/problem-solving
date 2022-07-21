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
public ListNode reverseBetween(ListNode head, int left, int right) {
    if(head==null ||head.next==null)
        return head;

    ListNode be=left==1?null:head;
    int i=1;

    while(i<left-1){
        be=be.next;
        i++;
    }

    ListNode re=be==null?head:be.next;
    ListNode rb=re;
    int x=right-left+1;

    ListNode prev=null;

    while(x!=0 ){
        ListNode next=rb.next;
        rb.next=prev;
        prev=rb;
        rb=next;
        x--;
    }


    if(be!=null)
        be.next=prev;
    else
        head=prev;
    re.next=rb;


    return head;
}
}