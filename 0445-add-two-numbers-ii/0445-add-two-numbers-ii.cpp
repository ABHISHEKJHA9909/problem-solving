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
    int len(ListNode* node){
        int res=0;
        while(node!=NULL){
            res++;
            node=node->next;
        }
        return res;
    }
    
    ListNode* add_before(ListNode* node,int n,int num){
        while(n--){
            ListNode* newNode=new ListNode(num);
            newNode->next=node;
            node=newNode;
        }
        return node;
    }
    
    int add(ListNode* l1,ListNode* l2){
        if(l1==NULL)
            return 0;
        
        int carry=add(l1->next,l2->next);
        l1->val+=(l2->val+carry);
        carry=l1->val/10;
        l1->val=l1->val%10;
        return carry;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n=len(l1),m=len(l2);
        if(n<m){
            swap(n,m);
            swap(l1,l2);
        }
        
        l2=add_before(l2,n-m,0);
        
        if(add(l1,l2))
            return add_before(l1,1,1);
        return l1;
    }
};