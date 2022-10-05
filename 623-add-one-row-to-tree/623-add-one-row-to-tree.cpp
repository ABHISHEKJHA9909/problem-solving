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
    TreeNode* fun(TreeNode* root,int val,int d,int l){
        if(d==1)
            return new TreeNode(val,l==1?root:NULL,l==1?NULL:root);
        if(root==NULL)
            return NULL;
        root->right=fun(root->right,val,d-1,0);
        root->left=fun(root->left,val,d-1,1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return fun(root,val,depth,1);
    }
};