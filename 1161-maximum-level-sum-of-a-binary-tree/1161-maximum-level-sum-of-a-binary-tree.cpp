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
    int maxLevelSum(TreeNode* root) {
        int res=INT_MIN,lev=1,ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(q.size()){
            int curr=0;
            
            for(int i=0,n=q.size();i<n;i++){
                root=q.front(),q.pop();
                
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                
                curr+=root->val;
            }
            if(curr>res){
                res=curr;
                ans=lev;
            }
            lev++;
        }
        
        
        return ans;
    }
};