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

// Logic : Reverse linked list twice so that it will be easy to delete next smaller
class Solution {
private:
    void deleteSmaller(ListNode *&head){
        if (head == NULL || head->next == NULL)
            return; 
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr){
            if(curr->val < prev->val){
                curr = curr->next;
                prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    void reverseLL(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
            return; 
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next = curr->next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        // Initial Reverse
        reverseLL(head);
        // Deletion Code
        deleteSmaller(head);
        // Reverse LL again to make it original again
        reverseLL(head);
        return head;
    }
};