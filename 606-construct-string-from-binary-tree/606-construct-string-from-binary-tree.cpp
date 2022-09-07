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
    string res="";
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return "";
        if(root->left==NULL && root->right==NULL)
            return to_string(root->val);
        
        string curr=to_string(root->val);
        curr+="("+tree2str(root->left)+")";
        if(root->right)
            curr+="("+tree2str(root->right)+")";
        return curr;
        
    }
};