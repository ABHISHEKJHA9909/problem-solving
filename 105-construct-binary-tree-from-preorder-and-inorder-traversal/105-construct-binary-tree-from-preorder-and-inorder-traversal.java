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
    int pre[]=new int[3001];
    int in[]=new int[3001];
    int k=0;
    
    TreeNode solve(int i,int j){
        if(i>j)
            return null;
        
        TreeNode curr=new TreeNode();
        int x=0;
        for(x=i;x<=j;x++){
            if(in[x]==pre[k])
                break;
        }
        
        curr.val=pre[k++];
        curr.left=solve(i,x-1);
        curr.right=solve(x+1,j);
        return curr;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for(int i=0;i<preorder.length;i++)pre[i]=preorder[i];
        for(int i=0;i<inorder.length;i++)in[i]=inorder[i];
        return solve(0,preorder.length-1);
    }
}