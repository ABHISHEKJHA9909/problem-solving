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
    // map<int,vector<TreeNode*>>m;
    
    vector<TreeNode*> rec(int n,unordered_map<int,vector<TreeNode*>>&m){
        if(m.find(n)!=m.end())
            return m[n];
        if(n==1)
            return m[n]={new TreeNode(0)};
        vector<TreeNode*>curr;
        
        for(int i=1;i<=n-2;i+=2){
            vector<TreeNode*>left=rec(i,m);
            vector<TreeNode*>right=rec(n-1-i,m);
            
            for(auto &l:left){
                for(auto &r:right){
                    TreeNode* node=new TreeNode(0);
                    node->left=l;
                    node->right=r;
                    curr.push_back(node);
                }
            }
        }
        
            
        return m[n]=curr;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>>mm;
        return rec(n,mm);
    }
};