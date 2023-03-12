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
        PriorityQueue<ListNode> pq=new PriorityQueue<ListNode>(new Comparator<ListNode>(){
            @Override
            public int compare(ListNode a,ListNode b){
                if(a.val<b.val)
                    return -1;
                else if(a.val==b.val)
                    return 0;
                else
                    return 1;
            }
        });
        for(ListNode l:lists){
            if(l!=null)
                pq.add(l);
        }
        
        ListNode dummy=new ListNode(-1);
        ListNode head=dummy;
        while(pq.size()!=0){
            head.next=pq.poll();
            head=head.next;
            
            if(head.next!=null)
                pq.add(head.next);
        }
        
        return dummy.next;
    }
}