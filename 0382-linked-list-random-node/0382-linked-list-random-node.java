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
    
    ListNode head;
    public Solution(ListNode head) {
        this.head=head;
    }
    
    public int getRandom() {
        int till=0;
        ListNode curr=head;
        
        ListNode rand=null;
        
        while(curr!=null){
            ++till;
            int randindex=(int)(Math.random()*1e6)%till;
            if(randindex==till-1)
                rand=curr;
            curr=curr.next;
        }
        
        return rand.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */