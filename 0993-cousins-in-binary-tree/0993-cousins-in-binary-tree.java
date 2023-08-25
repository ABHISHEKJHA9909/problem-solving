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
    private int dep_1;
    private int dep_2;
    private TreeNode par_1;
    private TreeNode par_2;
    
    void rec(TreeNode root,TreeNode par,int dep,int n1,int n2){
        if(root==null)
            return;
        if(root.val==n1){
            dep_1=dep;
            par_1=par;
        }
        if(root.val==n2){
            dep_2=dep;
            par_2=par;
        }
        rec(root.left,root,dep+1,n1,n2);
        rec(root.right,root,dep+1,n1,n2);
    }
    
    public boolean isCousins(TreeNode root, int x, int y) {
        
        dep_1=-1;
        dep_2=-1;
        par_1=null;
        par_2=null;
        
        rec(root,null,0,x,y);
        
        if(dep_1!=-1 && dep_2!=-1 && dep_1==dep_2 && par_1!=par_2){
            return true;
        }
        return false;
    }
}