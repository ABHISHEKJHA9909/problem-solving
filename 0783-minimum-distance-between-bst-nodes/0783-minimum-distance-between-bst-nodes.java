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
    int ans=Integer.MAX_VALUE;
    
    private int[] rec(TreeNode root){
        if(root==null){
                int []curr={1000000,-1000000};
                return curr;
        }
        
        int l[]=rec(root.left);
        int r[]=rec(root.right);
        
        // System.out.print(root.val-l[1]+" "+r[0]-root.val);
        ans=Math.min(ans,root.val-l[1]);
        ans=Math.min(ans,r[0]-root.val);
        
        
        l[0]=Math.min(l[0],root.val);
        l[1]=Math.max(r[1],root.val);
        // System.out.println(root.val+" "+l[0]+" "+l[1]+" "+ans);
        return l;
    }
    
    public int minDiffInBST(TreeNode root) {
        rec(root);
        return ans;
    }
}