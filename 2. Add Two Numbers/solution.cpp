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
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        while(l1 != NULL && l2 != NULL){
            int sum = carry + l1->val + l2->val;
            int f_sum = sum % 10;
            insertAtTail(ansHead,ansTail,f_sum);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int sum = carry + l1->val ;
            int f_sum = sum % 10;
            insertAtTail(ansHead,ansTail,f_sum);
            carry = sum/10;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int sum = carry + l2->val ;
            int f_sum = sum % 10;
            insertAtTail(ansHead,ansTail,f_sum);
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry != 0){
            insertAtTail(ansHead,ansTail,carry);
        }
        return ansHead;
    }
};
