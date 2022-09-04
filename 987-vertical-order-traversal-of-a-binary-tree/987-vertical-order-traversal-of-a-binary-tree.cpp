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
    
    void dfs(TreeNode* root,map<int,vector<pair<int,int>>>&m,int i,int j){
        if(root==NULL)
            return ;
        m[j].push_back({i,root->val});
        dfs(root->left,m,i+1,j-1);
        dfs(root->right,m,i+1,j+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>m;
        dfs(root,m,0,0);
        
        vector<vector<int>>res;
        
        for(auto &[x,y]:m){
            sort(y.begin(),y.end());
            vector<int>curr;
            for(auto &j:y){
                curr.push_back(j.second);
            }
            res.push_back(curr);
        }
        return res;
    }
};