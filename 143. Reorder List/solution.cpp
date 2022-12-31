/*
805 ms
17.8 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
*/

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
    void reorderList(ListNode* head) {
        // Only one element list
        if(head->next == NULL){
            return;
        }
        // Onl;y two element list
        if(head->next->next == NULL){
            return;
        }

        // Find out last and second last elements
        ListNode* temp1 = head;
        ListNode* temp2 = NULL;
        while(temp1->next != NULL){
            temp2 = temp1;
            temp1 = temp1->next;
        }

        // Findout next head, Do the pointer manipulation and ask recursion to solve remaining LL
        ListNode* next_head = head->next;
        temp1->next = next_head;
        temp2->next = NULL;
        head->next = temp1;
        reorderList(next_head);
    }
};