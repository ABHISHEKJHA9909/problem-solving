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
    ArrayList<Integer>arr=new ArrayList<Integer>();
    
    int rec(TreeNode root,int id,int d){
        if(root==null)  return 0;
        if(d>=arr.size())arr.add(id);

        return Math.max(id-arr.get(d)+1,Math.max(rec(root.left,id*2,d+1),rec(root.right,id*2+1,d+1)));
    }
    
    public int widthOfBinaryTree(TreeNode root) {
        return rec(root,1,0);
    }
}