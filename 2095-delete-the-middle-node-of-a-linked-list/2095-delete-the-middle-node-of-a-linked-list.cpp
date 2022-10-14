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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* x=head,*x2=head,*prev=NULL;
        
        while(x2 && x2->next){
            prev=x;
            x2=x2->next->next;
            x=x->next;
        }
        
        if(prev==NULL)
            return NULL;
        prev->next=prev->next->next;
        return head;
    }
};