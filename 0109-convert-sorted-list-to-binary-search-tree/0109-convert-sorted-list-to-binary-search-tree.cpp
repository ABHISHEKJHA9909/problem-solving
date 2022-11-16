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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<ListNode*> get(ListNode* l){
        ListNode *slow=l,*fast=l,*ll=l;
        
        ListNode *prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        
        if(prev!=NULL){
            prev->next=NULL;
            prev=ll;
        }
        
        return {prev,slow,slow->next};
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        
        vector<ListNode*>arr=get(head);
        TreeNode *root=new TreeNode(arr[1]->val);
        
        if(arr[0]!=NULL)
            root->left=sortedListToBST(arr[0]);
        if(arr[2]!=NULL)
            root->right=sortedListToBST(arr[2]);
        
        return root;
    }
};