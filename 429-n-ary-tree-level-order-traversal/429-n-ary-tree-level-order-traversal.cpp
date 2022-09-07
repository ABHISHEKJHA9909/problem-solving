/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        if(root!=NULL)
            q.push(root);
        vector<vector<int>>res;
        
        while(q.size()){
            vector<int>curr;
            int n=q.size();
            for(int i=0;i<n;i++){
                root=q.front();
                q.pop();
                
                curr.push_back(root->val);
                for(Node* &x:root->children){
                    q.push(x);
                }
            }
            res.push_back(curr);
        }
        
        return res;
    }
};