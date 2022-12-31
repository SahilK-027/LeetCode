/*
14 ms
8.3 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Three pointer
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head; //Checking for Empty or single node LL
        }
        //Using 3 ptr approach
        ListNode* current = head;
        ListNode* previous = NULL;
        ListNode* next = current->next;
        while(current!=NULL){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
        return head;
    }
};