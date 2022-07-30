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
    void inorder(TreeNode* root,vector<int> &res,int k){
        if(root==NULL)
            return;
        
        inorder(root->left,res,k);
        
        if(res.size()==k)
            return;
        res.push_back(root->val);
        
        inorder(root->right,res,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int>in;
        inorder(root,in,k);
        return in[k-1];
    }
};