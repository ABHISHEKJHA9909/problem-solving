/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    int rec(TreeNode* root,TreeNode *p,TreeNode* q){
        if(root==NULL)
            return 0;
        int x=root->val==p->val||root->val==q->val;
        x+=rec(root->left,p,q);
        x+=rec(root->right,p,q);
        if(x==2){
            res=root;
        }
        return x>0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root,p,q);
        return res;
    }
};