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
    void fun(TreeNode* root,int val,int d){
        if(root==NULL)
            return;
        if(d==2){
            TreeNode *curr= new TreeNode(val);
            curr->right=root->right;
            root->right=curr;
            curr=new TreeNode(val);
            curr->left=root->left;
            root->left=curr;
            return;
        }
        fun(root->left,val,d-1);
        fun(root->right,val,d-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
            return new TreeNode(val,root,NULL);
        fun(root,val,depth);
        return root;
    }
};