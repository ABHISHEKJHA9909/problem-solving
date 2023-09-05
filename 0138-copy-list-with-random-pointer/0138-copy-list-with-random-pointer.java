/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node,Node> m=new HashMap<Node,Node>();
        
        Node dummy=new Node(-1);
        Node new_node=dummy;
        Node old_node=head;
        
        
        while(old_node!=null){
            if(m.get(old_node)!=null){
                new_node.next=m.get(old_node);
            }
            else{
                new_node.next=new Node(old_node.val);
                m.put(old_node,new_node.next);
            }
            new_node=new_node.next;
            if(old_node.random!=null){
                if(m.get(old_node.random)!=null){
                    new_node.random=m.get(old_node.random);
                }
                else{
                    new_node.random=new Node(old_node.random.val);
                    m.put(old_node.random,new_node.random);
                }
            }
            
            old_node=old_node.next;
            
        }
        
        return dummy.next;
    }
}