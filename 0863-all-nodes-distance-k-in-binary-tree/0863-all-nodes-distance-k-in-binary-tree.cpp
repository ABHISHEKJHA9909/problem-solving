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
    vector<int>res;
    map<TreeNode*,TreeNode*>m;
    
    void par(TreeNode* root,int k,TreeNode* chi){
        if(root==NULL)
            return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        par(m[root],k-1,root);
        if(root->left!=chi)
            child(root->left,k-1);
        if(root->right!=chi)
            child(root->right,k-1);
    }
    
    void child(TreeNode* root,int k){
        if(root==NULL)
            return;
        if(k==0){
            res.push_back(root->val);
            return;
        }
        child(root->left,k-1);
        child(root->right,k-1);
    }
    
    void rec(TreeNode* root,TreeNode* target,int k){
        if(root==NULL)
            return;
        if(root==target){
            par(root,k,root);
            return;
        }
        m[root->left]=root;
        m[root->right]=root;
        rec(root->left,target,k);
        rec(root->right,target,k);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        m[root]=NULL;
        rec(root,target,k);
        
        return res;
    }
};