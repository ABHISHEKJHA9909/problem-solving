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
    vector<int>arr;
    
    void inorder(TreeNode* root){
        if(root==NULL)  return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    TreeNode* rec(int ll,int rr){
        if(ll>rr)
            return NULL;
        int i=(ll+rr+1)/2;
        TreeNode *root=new TreeNode(arr[i]);
        root->left=rec(ll,i-1);
        root->right=rec(i+1,rr);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* ru) {
        inorder(ru);
        return rec(0,arr.size()-1);
    }
};