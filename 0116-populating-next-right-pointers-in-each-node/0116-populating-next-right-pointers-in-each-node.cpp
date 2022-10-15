/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        queue<Node*>q;
        if(root)
            q.push(root);
        Node* res=root;
        
        while(q.size()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                root=q.front(); q.pop();
                if(q.size())
                root->next=q.front();
                if(root->left)
                    q.push(root->left),q.push(root->right);
            }
            root->next=NULL;
        }
        
        return res;
    }
};