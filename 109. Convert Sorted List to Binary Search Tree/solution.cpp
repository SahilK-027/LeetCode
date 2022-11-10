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
private:
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // No list
        if(head == NULL){
            return NULL;
        }
        // Single node
        if(head->next == NULL){
            return (new TreeNode(head->val));
        }
        
        // find mid of list 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;
        
        while(fast != NULL && fast->next != NULL){
            mid = slow;
            slow = slow -> next;
            fast = fast->next ->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        mid->next = NULL;
        
        // Recursive call
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};