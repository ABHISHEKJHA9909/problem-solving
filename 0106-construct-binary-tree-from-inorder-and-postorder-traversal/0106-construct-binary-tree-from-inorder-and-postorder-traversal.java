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
    int k;
    
    TreeNode rec(int[] in ,int[] post,int i,int j){
        // System.out.println(k+" "+i+" "+j);
        if(k<0 || i>j)
            return null;
        
        TreeNode root=new TreeNode(post[k]);
        
        int l=i;
        while(in[l]!=post[k])
            l++;
        k--;
        
        root.right=rec(in,post,l+1,j);
        root.left=rec(in,post,i,l-1);
        
        return root;
    }
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        k=inorder.length-1;
        return rec(inorder,postorder,0,k);
    }
}