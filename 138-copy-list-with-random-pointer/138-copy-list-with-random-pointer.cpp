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
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        
        while(head!=NULL){
            Node *next=head->next;
            Node *new_Node=new Node(head->val);
            head->next=new_Node;
            new_Node->next=next;
            head=next;
        }
        
        head=curr;
        
        while(head!=NULL){
            if(head->random!=NULL){
                head->next->random=head->random->next;
            }
            head=head->next->next;
        }
        
        head=curr;
        
        Node *res,*ans;
        if(head!=NULL){
            res=head->next;
            ans=res;
        }
        
        while(head!=NULL){
            head->next=head->next->next;
            if(res->next!=NULL){
                res->next=res->next->next;
                res=res->next;
            }
            head=head->next;
        }
        
        return ans;
    }
};