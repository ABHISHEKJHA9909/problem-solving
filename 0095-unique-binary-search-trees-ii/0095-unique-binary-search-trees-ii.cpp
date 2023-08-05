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
    map<pair<int,int>,vector<TreeNode*>>m;
    
    vector<TreeNode*> rec(int i,int j){
        if(i==j){
            return {new TreeNode(i)};
        }
        
        if(m.find({i,j})!=m.end())
            return m[{i,j}];
        vector<TreeNode*>res;
        
        for(int k=i;k<=j;k++){
            vector<TreeNode*> left=rec(i,k-1);
            vector<TreeNode*> right=rec(k+1,j);
            
            if(left.size() && right.size()){
                for(int i=0;i<left.size();i++){
                    for(int j=0;j<right.size();j++){
                        TreeNode *curr=new TreeNode(k);
                        curr->right=right[j];
                        curr->left=left[i];
                        res.push_back(curr);
                    }
                }
            }
            else if(left.size()){
                for(int i=0;i<left.size();i++){
                    TreeNode *curr=new TreeNode(k);
                    curr->left=left[i];
                    res.push_back(curr);
                }
            }
            else{
                for(int i=0;i<right.size();i++){
                    TreeNode *curr=new TreeNode(k);
                    curr->right=right[i];
                    res.push_back(curr);
                }
            }
        }
        
        return m[{i,j}]=res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return rec(1,n);
    }
};