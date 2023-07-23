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
    
    vector<TreeNode*> rec(int n){
        if(n==1)
            return {new TreeNode(0)};
            
        
        vector<TreeNode*>curr;
        
        for(int i=1;i<=n-2;i+=2){
            vector<TreeNode*>left=rec(i);
            vector<TreeNode*>right=rec(n-1-i);
            
            for(auto &l:left){
                for(auto &r:right){
                    TreeNode* node=new TreeNode(0);
                    node->left=l;
                    node->right=r;
                    curr.push_back(node);
                }
            }
        }
        
            
        return curr;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return rec(n);
    }
};