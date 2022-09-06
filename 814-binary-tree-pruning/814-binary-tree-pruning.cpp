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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        TreeNode* right=pruneTree(root->right);
        TreeNode* left=pruneTree(root->left);
        
        if(right==NULL)
            root->right=NULL;
        if(left==NULL)
            root->left=NULL;
        
        if(root->val==1||right||left)
            return root;
        return NULL;
    }
};