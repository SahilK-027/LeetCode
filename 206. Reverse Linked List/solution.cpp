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
//RECURSIVE APPROACH 2
class Solution {
    ListNode* reverse(ListNode*& head){
        if(head == NULL || head->next ==NULL){
            return head;
        }
        //Asking recursion to give remiaining reversed list
        ListNode* recHead = reverse(head->next); //recursion will reverse it
        
        //Our 2 jobs left
        head->next->next = head;
        head->next = NULL;
        return recHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};