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
    private int length(ListNode head){
        int len=0;
        while(head!=null){
            len++;
            head=head.next;
        }
        return len;
    }
    
    public ListNode[] splitListToParts(ListNode head, int k) {
        int len=length(head);
        
        int size=(len+k-1)/k;
        int mx=len%k;
        if(mx==0)
            mx=k;
        int mn=k-mx;
        
        
        ListNode[] res=new ListNode[k];
        
        System.out.println(size+" "+mx+" "+mn);
        int i=0;
        if(size>0){
            while(mx-->0){
                res[i]=head;
                for(int j=0;j<size-1;j++){
                    head=head.next;
                }
                ListNode temp=head.next;
                head.next=null;
                head=temp;
                i++;
            }
        }
        
        if(size-1>0){
            while(mn-->0){
                res[i]=head;
                for(int j=0;j<size-2;j++){
                    head=head.next;
                }
                ListNode temp=head.next;
                head.next=null;
                head=temp;
                i++;
            }
        }
        
        return res;
    }
}