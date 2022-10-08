// Runtime: 3 ms
// Memory Usage: 7.5 MB

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Step 1.
        // If only one node present. OR 
        // left and right are equal no need to make any changes.
        if(head->next == NULL || left == right){
            return head;
        }
        
        // Step 2. Find the left and right position
        int left_cnt = 1;
        int right_cnt = 2;
        ListNode* left_ptr = head;
        ListNode* prev_left_ptr = NULL;
        ListNode* right_ptr = head->next;
        while(left_cnt<left){
            left_cnt++;
            prev_left_ptr = left_ptr ; 
            left_ptr = left_ptr->next;
        }
        while(right_cnt < right){
            right_cnt++;
            right_ptr = right_ptr->next;
        }
        
        // Step 3. Keep track of prev to left and next to right
        ListNode* middle_head = head;
        if(prev_left_ptr){
            middle_head = prev_left_ptr;
        }
        
        // Step 4. Reverse LL from left to right position
        ListNode* tail_ptr = right_ptr->next;
        ListNode* prev = NULL;
        ListNode* curr = left_ptr;
        ListNode* next = NULL;
        while(curr != tail_ptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Step 5. Attach the reversed LL to its appropriate position
        if(head == left_ptr){
            head->next = tail_ptr;
            return prev;
        }
        else{
            left_ptr->next = tail_ptr;
            middle_head->next = prev;
        }
        return head;
    }
};
