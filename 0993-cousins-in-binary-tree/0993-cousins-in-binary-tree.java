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
    private boolean answer;
    
    private int helper(TreeNode root,int x,int y){
        if(root==null)
            return -1;
        if(root.val==x||root.val==y)
            return 0;
        
        int l=helper(root.left,x,y);
        int r=helper(root.right,x,y);
        
        System.out.println(root.val+" "+l+" "+r);
        if(l>=1 && r>=1 &&  l==r && l!=0){
            answer=true;
        }
        if(l==-1 && r==-1)
            return -1;
        return Math.max(l,r)+1;
    }
    
    
    public boolean isCousins(TreeNode root, int x, int y) {
        answer=false;
        
        helper(root,x,y);
        
        return answer;
    }
}