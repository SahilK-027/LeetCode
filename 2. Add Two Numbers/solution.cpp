/*
50 ms
71.5 MB

TC : O(N)
SC : O(N)
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
private: 
    // The function to insert new node at the end of liost
    void insertAtTail(ListNode* &ansHead,ListNode* &ansTail,int f_sum){
        ListNode *n1 = new ListNode(f_sum);
        if(ansHead == NULL){
            ansHead = n1;
            ansTail = n1;
            return;
        }
        ansTail->next = n1;
        ansTail = n1;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Creating ans list
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        // Adding list1 and list2
        while(l1 != NULL && l2 != NULL){
            int sum = carry + l1->val + l2->val;
            int f_sum = sum % 10;
            insertAtTail(ansHead,ansTail,f_sum);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        // If list1 is not yet traversed completely 
        while(l1 != NULL){
            int sum = carry + l1->val ;
            int f_sum = sum % 10;
            insertAtTail(ansHead,ansTail,f_sum);
            carry = sum/10;
            l1 = l1->next;
        }
        // If list2 is not yet traversed completely 
        while(l2 != NULL){
            int sum = carry + l2->val ;
            int f_sum = sum % 10;
            insertAtTail(ansHead,ansTail,f_sum);
            carry = sum/10;
            l2 = l2->next;
        }
        // If final carry is non zero
        if(carry != 0){
            insertAtTail(ansHead,ansTail,carry);
        }
        return ansHead;
    }
};
