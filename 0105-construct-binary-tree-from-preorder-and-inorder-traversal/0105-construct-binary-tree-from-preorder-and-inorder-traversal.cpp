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
    TreeNode* rec(int& i,int l,int r,vector<int>& pre,vector<int>& in){
        if(l>r)
            return NULL;
        i++;
        // cout<<i<<' '<<l<<' '<<r<<endl;
        TreeNode* curr=new TreeNode(pre[i]);
        
        int ind;
        for(int k=l;k<=r;k++){
            if(in[k]==pre[i]){
                ind=k;
                break;
            }
        }
        
        curr->left=rec(i,l,ind-1,pre,in);
        curr->right=rec(i,ind+1,r,pre,in);
        
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=-1;
        return rec(i,0,inorder.size()-1,preorder,inorder);
    }
};