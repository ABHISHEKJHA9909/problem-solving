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
    ArrayList<Integer>arr=new ArrayList<>();
    Stack<Integer>s=new Stack<Integer>();
    
    public void rec(ListNode head){
        if(head==null)
            return;
        rec(head.next);
        while(s.size()>0 && s.peek()<=head.val)
            s.pop();
        if(s.size()>0)
            arr.add(s.peek());
        else
            arr.add(0);
        s.push(head.val);
    }
    
    public int[] nextLargerNodes(ListNode head) {
        rec(head);
        int []res=new int[arr.size()];
        for(int i=0;i<arr.size();i++)
            res[arr.size()-1-i]=arr.get(i);
        // Collections.reverse(res);
        return res;
    }
}