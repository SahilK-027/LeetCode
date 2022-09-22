/*
Runtime: 0 ms
Memory Usage: 7.7 MB
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
    ListNode* swapPairs(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        //Step 1. Swap first two nodes
        int count = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL && count < 2){
            count++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //Step 2. Recursion will reverse remaining list and will return new head
        if(next != NULL){
            ListNode* NewHead = swapPairs(next);
        //Step 3. Attach newhead to our head
            head->next = NewHead;
        }
        //return prev
        return prev; 
    }
};
