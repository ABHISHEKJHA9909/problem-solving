/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode *head){
        ListNode* prev=NULL;
        
        while(head!=NULL){
            ListNode* next=head->next;
            head->next=prev;
            
            prev=head;
            head=next;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return;
        
        ListNode *slow=head,*fast=head,*prev=NULL;
        
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *l2=slow;
        prev->next=NULL;
        ListNode *l1=head;
        
        l2=reverse(l2);
        
        while(l1!=NULL && l2!=NULL){
            ListNode* next=l1->next;
            l1->next=l2;
            l1=l1->next;
            l2=next;
        }
    }
};