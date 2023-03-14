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
    int sum=0;
    void rec(TreeNode root,int curr){
        if(root==null)
            return;
        
        curr*=10;
        curr+=root.val;
        
        if(root.right==null && root.left==null){
            sum+=curr;
            return;
        }
        rec(root.left,curr);
        rec(root.right,curr);
    }
    public int sumNumbers(TreeNode root) {
        rec(root,0);
        return sum;
    }
}