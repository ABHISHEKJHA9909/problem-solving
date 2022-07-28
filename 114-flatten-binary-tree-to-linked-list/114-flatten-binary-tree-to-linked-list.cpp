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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* r=root->right;
        TreeNode* l=root->left;
        if(l!=NULL){
            TreeNode* last=l;
            root->left=NULL;
            while(last->right!=NULL){
                last=last->right;
            }
            
            root->right=l;
            last->right=r;
        }
        
        return;
    }
};