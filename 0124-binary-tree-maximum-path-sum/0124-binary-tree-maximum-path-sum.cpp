/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=INT_MIN;

    int rec(TreeNode* root){
        if(root==NULL)
            return -2000;
        int l=rec(root->left);
        int r=rec(root->right);

        res=max(res,l);
        res=max(res,r);
        res=max(res,root->val+l+r);

        return root->val + max(max(l,r),0);
    }

    int maxPathSum(TreeNode* root) {
        res=max(res,rec(root));
        return res;
    }
};