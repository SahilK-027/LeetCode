/*
Runtime: 15 ms
Memory Usage: 11.9 MB
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
    int getLength(ListNode* head){
        int length = 1;
        while(head->next != NULL){
            head = head -> next;
            length ++;
        }
        return length;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head == NULL || head->next == NULL || k==0){
            return head;
        }
        int length = getLength(head);
        /* We are finding length because though k = 5 but if list has length 3 it will only get rotated 2 times because after every 3 rotations list will be back in original form */
        int newk = k % length;  
        while(newk--)
        {
            ListNode* last = head;
            ListNode* prev_last = NULL;
            while(last-> next != NULL)
            {
                prev_last = last;
                last = last->next;
            }
            last->next = head ;
            prev_last -> next = NULL;
            head = last;
        }
        return head;
    }
};
