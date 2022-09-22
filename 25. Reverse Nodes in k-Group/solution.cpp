/*
Runtime: 20 ms
Memory Usage: 11.7 MB
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
private:
    int getlength(ListNode* next){
        int length = 0;
        ListNode* temp = next;
        while( temp!=NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // 1. Base case
        if(head == NULL || k==1){
            return head;
        }
        
        // 2. We will reverse first k nodes
        int cnt = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL && cnt < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;            
        }
        
        
        // 3. First we will find length of remaining list and if length of remaining list is greater than or equal to k then only we will reverse further part
        int length = getlength(next);
        
        // 4. We will ask recursion to reverse next k nodes and return new head
        ListNode* newHead = next;
        if(next != NULL && length >= k){
             newHead = reverseKGroup(next, k);
        }
        
        // 5. Attach newhead to linked list which we have reversed 
        head->next = newHead;
        
        // 6. Return prev 
        return prev;
    }
};
