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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>s;
        
        if(root!=NULL){
            s.push(root);
        }
        
        int depth=0;
        
        while(s.size()){
            int n=s.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=s.front();
                s.pop();
                if(curr->left!=NULL)
                    s.push(curr->left);
                if(curr->right!=NULL)
                    s.push(curr->right);
            }
            depth++;
        }
        
        return depth;
    }
};