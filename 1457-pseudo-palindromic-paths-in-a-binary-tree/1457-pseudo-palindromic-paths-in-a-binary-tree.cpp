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
    int x=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->right==NULL && root->left==NULL){
            x^=(1<<(root->val));
            int set=0;
            for(int i=1;i<=9;i++){
                if(x&(1<<i))
                    set++;
            }
            
            x^=(1<<(root->val));
            return set<=1;
        }
        x^=(1<<(root->val));
        int l=0,r=0;
        if(root->left)
            l=pseudoPalindromicPaths(root->left);
        if(root->right)
            r=pseudoPalindromicPaths(root->right);
        x^=(1<<(root->val));
        return l+r;
    }
};