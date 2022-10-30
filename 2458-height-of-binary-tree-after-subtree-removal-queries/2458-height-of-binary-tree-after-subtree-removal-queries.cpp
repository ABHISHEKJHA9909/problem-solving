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
    unordered_map<int,vector<int>>m;
    unordered_map<int,int>ml;
    unordered_map<int,int>mh;
    
    int height(TreeNode* root,int curr){
        if(root==NULL)
            return 0;
        ml[root->val]=curr;
        int l=height(root->left,curr+1);
        int r=height(root->right,curr+1);
        
        m[curr].push_back(max(l,r));
        mh[root->val]=max(l,r);
        return 1+max(l,r);
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int h=height(root,1)-1;
        for(auto &i:m){
            sort(i.second.begin(),i.second.end());
        }
        
        vector<int>res;
        
        int l;
        for(int &i:queries){
            l=ml[i];
            if(mh[i]!=m[l].back()){
                res.push_back(h);
            }
            else{
                if(m[l].size()!=1){
                    res.push_back(h-m[l].back()+m[l][m[l].size()-2]);
                }
                else{
                    res.push_back(h-m[l].back()-1);
                }
            }
        }
        
        return res;
    }
};