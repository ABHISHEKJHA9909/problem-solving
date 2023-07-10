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
    int rec(TreeNode* root){
        if(root==NULL)
            return INT_MAX;
        if(root->right==NULL && root->left==NULL)
            return 1;
        
        return 1+min(rec(root->left),rec(root->right));
    }
    
    int minDepth(TreeNode* root) {
        return root==NULL?0:rec(root);
    }
};