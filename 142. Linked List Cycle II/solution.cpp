/*
16 ms
7.7 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
    //Floyd's algorithm to find the begining of cycle
public:
    ListNode *detectCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        //No node in list
        if(head == NULL){
            return NULL;
        }
        
        // Step 1. Using floyd's alg to detect loop
        ListNode *fast = head;
        ListNode *slow = head;
        bool Cycle_Present = false;
        while(slow != NULL && fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                Cycle_Present = true;
                break;
            }
        }
        if(!Cycle_Present){
            return NULL;
        }
        
        // Step 2. If cycle found
        slow = head;
        while(slow != fast){
        // Step 3. Now move them one step at a time
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};