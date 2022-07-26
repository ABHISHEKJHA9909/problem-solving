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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode *node=head,*res=head,*prev=NULL;
        
        while(head!=NULL){
            head=head->next;
            if(length>=n){
                prev=node;
                node=node->next;
            }
            length++;
        }
        
        if(prev==NULL)
            res=res->next;
        else
            prev->next=prev->next->next;
        
        return res;
    }
};