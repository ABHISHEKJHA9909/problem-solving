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
    int mh=0;
    int cnt=0;
    
    int post(TreeNode* root,int h){
        if(root==NULL){
            if(h==mh){
                cnt++;
                return 0;
            }
            return  pow(2,mh)-cnt-1;
        }
        int x=post(root->right,h+1);
        if(x!=0)
            return x;
        return post(root->left,h+1);
    }
    
    int countNodes(TreeNode* root) {
        TreeNode* cp=root;
        while(cp!=NULL)
            cp=cp->left,mh++;
        return post(root,1);
    }
};