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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* copy=head;
        int len=0;
        while(copy!=NULL){
            len++;
            copy=copy->next;
        }
        
        ListNode* l1,* l2;
        
        copy=head;
        int i=1;
        while(copy!=NULL){
            if(i==k)
                l1=copy;
            if(i==(len-k+1))
                l2=copy;
            copy=copy->next;
            i++;
        }
        swap(l1->val,l2->val);
        return head;
    }
};