/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string s="";
        
        
        while(q.size()){
            root=q.front();
            q.pop();
            if(root){
                s+=to_string(root->val)+" ";
                q.push(root->left);
                q.push(root->right);
            }
            else{
                s+="N ";
            }
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        stringstream ss(s);
        TreeNode *root=new TreeNode(),*dummy=new TreeNode();
        TreeNode *ans=root;
        root->right=dummy;
        root->left=dummy;
        queue<TreeNode*>q;
        q.push(root);
        
        while(ss>>s){
            root=q.front();
            q.pop();
            TreeNode *curr;
            if(s=="N")
                curr=NULL;
            else{
                curr=new TreeNode(stoi(s));
                curr->right=dummy;
                curr->left=dummy;
                q.push(curr);
                q.push(curr);
            }
            if(root->left==dummy){
                root->left=curr;
            }
            else{
                root->right=curr;
            }
        }
        return ans->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));