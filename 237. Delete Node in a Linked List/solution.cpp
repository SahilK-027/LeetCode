/*
10 ms
7.7 MB

TC : O(N)
SC : O(height)
*/

/**
 * @author : SahilK-027
 * @brief : Linked list
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
public:
    void deleteNode(ListNode* node) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        //Step 1. Take a temp pointig to next node of given node
        ListNode* temp = node->next; 
        
        //Step 2. Copy value of temp to our node
        *node = *temp;
        
        //Step 3. Update the pointer of our node to next of temp which will remove temp from list without actually deleting it
        node->next = temp->next;
    }
};