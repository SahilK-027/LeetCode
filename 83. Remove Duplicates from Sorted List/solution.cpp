/*
16 ms
11.8 MB

TC : O(N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iteration
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
    ListNode* deleteDuplicates(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            else{
                curr->next = curr->next;
                curr = curr->next;
                curr->next = curr->next;
            }
        }
        curr->next = curr->next;
        return head;
    }
};
