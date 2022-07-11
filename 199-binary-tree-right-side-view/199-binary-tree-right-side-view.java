/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer>res=new ArrayList<Integer>();
        Queue<TreeNode>q=new LinkedList<TreeNode>();
        
        if(root!=null)
            q.add(root);
        
        while(q.size()>0){
            res.add(q.peek().val);
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.poll();
                if(root.right!=null)
                    q.add(root.right);
                if(root.left!=null)
                    q.add(root.left);
            }
        }
        
        return res;
    }
}