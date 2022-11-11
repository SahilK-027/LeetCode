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
//Fast and slow ptr approach
class Solution {
private: 
    int getLength(ListNode* head){
        ListNode*temp=head;
        int length = 0;
        while(temp!=NULL){
            length++;
            temp=temp->next;
        }
        return length;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next ==NULL){ //One node in LL
            return NULL;
        }
        ListNode*fast;
        ListNode*slow;
        ListNode*prev_to_slow = NULL;
        int length = getLength(head);
        if(length%2 == 1){
            //Even length LL
            fast = head->next;
            slow = head;
        }
        else{
            //ODD Length LL
            fast = head;
            slow = head;
        }
        while(fast!=NULL){
            prev_to_slow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev_to_slow->next = slow->next;
        return head;
    }
};