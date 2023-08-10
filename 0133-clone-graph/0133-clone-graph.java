/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    
    private Node clone(Node node,HashMap<Node,Node> map){
        if(map.get(node)!=null)
            return map.get(node);
        
        Node newNode=new Node(node.val);
        map.put(node,newNode);
        for(Node adj:node.neighbors){
            newNode.neighbors.add(clone(adj,map));
        }
        
        return newNode;
    }
    public Node cloneGraph(Node node) {
        if(node==null)
            return null;
        HashMap<Node,Node>map=new HashMap<Node,Node>();
        return clone(node,map);
    }
}