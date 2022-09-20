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
    int rec(TreeNode* root,int i){
        if(root==NULL)
            return 0;
        return (root->val>=i?1:0)+rec(root->left,max(i,root->val))+rec(root->right,max(i,root->val));
    }
    
    int goodNodes(TreeNode* root) {
        return rec(root,INT_MIN);
    }
};