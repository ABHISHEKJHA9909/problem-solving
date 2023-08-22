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
    
    int rec(TreeNode* root,int &res){
        if(root==NULL)
            return 0;
        
        int l=rec(root->left,res);
        int r=rec(root->right,res);
        int curr=root->val;
        
        res=max({res,curr+l+r});
        
        return max({0,curr+l,curr+r});
    }
    
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        rec(root,res);
        
        return res;
    }
};