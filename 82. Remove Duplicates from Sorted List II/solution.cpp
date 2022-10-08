// Runtime: 10 ms
// Memory Usage: 11.3 MB

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
    /*Only solve one case of duplicate head and recursion will take care of remaining list*/
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // Base Case
        if(head == NULL || head->next ==NULL){
            return head;
        }
        // Strep 1. while head itself is duplicate
        while(head != NULL && head->next != NULL && head->next->val == head->val){
             while(head->next != NULL && head->next->val == head->val){
                head = head->next;
            }
            head = head->next;
        }
        if(head == NULL || head->next ==NULL){
            return head;
        }
        
        // Step 2. 
        // (a) When got unique head no need to worry about head now, 
        // (b) so we will ask recursion to delete duplicates from next nodes onwards and return its unique head 
        // (c) then we'll attach that unique head returned by recursion with our unique head.
        ListNode* temp = head ->next;
        head->next = deleteDuplicates(temp);
        
        // Step 3. After we got answer we will return head
        return head;
    }
};
