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
    ListNode *is(ListNode* head,ListNode* curr,bool &b){
        if(head==NULL)
            return curr;
        curr=is(head->next,curr,b);
        b=b&&(curr->val==head->val);
        return curr->next;
    }
    bool isPalindrome(ListNode* head) {
        bool b=1;
        is(head,head,b);
        return b;
    }
};