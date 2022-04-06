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
    
    TreeNode* balanceBST(TreeNode* ru) {
        if(ru==NULL)
            return NULL;
        arr.clear();
        inorder(ru);
        int i=arr.size()/2;
        TreeNode *root=new TreeNode(arr[i]);
        int l=i-1;
        TreeNode* copy=root;
        while(l>=0){
            copy->left=new TreeNode(arr[l--]);
            copy=copy->left;
        }
        copy=root;
        int r=i+1;
        while(r<arr.size()){
            copy->right=new TreeNode(arr[r++]);
            copy=copy->right;
        }
        root->right=balanceBST(root->right);
        root->left=balanceBST(root->left);
        return root;
    }
};