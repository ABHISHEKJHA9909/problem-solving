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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>>res;
        
        queue<TreeNode*>q; q.push(root);
        
        while(q.size()){
            vector<int>curr;
            for(int i=0,n=q.size();i<n;i++){
                root=q.front(),q.pop();
                curr.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                
            }
            res.push_back(curr);
        }
        
        for(int i=0;i<res.size();i++){
            if(i&1){
                reverse(res[i].begin(),res[i].end());
            }
        }
        
        return res;
    }
};