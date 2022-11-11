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
    //RECURSIVE SOLUTION
public:
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // Base Case 
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        //PROCESSING
        ListNode* temp = head->next;
        ListNode * newNode = new ListNode(0);
        while(temp != NULL && temp->val != 0){
            newNode->val += temp->val;
            temp = temp->next;
        }
        
        //RECURSIVE CALL
        if(temp->next != NULL){
            newNode->next = mergeNodes(temp);
        }
        
        //RETURN ANS
        return newNode;
    }
};