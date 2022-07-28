/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*>m;
    
    Node* copyRandomList(Node* head) {
        Node *n=new Node(-1);
        Node *res=n;
        m[NULL]=NULL;
        Node *curr=new Node(-1);
        curr->next=head;
        head=curr;
        while(head!=NULL){
            if(m.find(head->next)!=m.end()){
                n->next=m[head->next];
            }
            else{
                n->next=new Node(head->next->val);
                m[head->next]=n->next;
            }
            if(m.find(head->random)!=m.end()){
                n->random=m[head->random];
            }
            else{
                n->random=new Node(head->random->val);
                m[head->random]=n->random;
            }
            head=head->next;
            n=n->next;
        }
        
        return res->next;
    }
};