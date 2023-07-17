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
    ListNode* reverse(ListNode* curr){
        ListNode* prev=NULL,* next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
    }
    
    ListNode* add(ListNode* l1,ListNode* l2){
        ListNode *res=new ListNode(-1);
        ListNode * dummy=res;
        int c=0;
        
        while(l1||l2||c){
            int x=c;
            if(l1){
                x+=l1->val;
                l1=l1->next;
            }
            if(l2){
                x+=l2->val;
                l2=l2->next;
            }
            c=x/10;
            x=x%10;
            res->next=new ListNode(x);
            res=res->next;
        }
        
        return reverse(dummy->next);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        
        return add(l1,l2);
    }
};