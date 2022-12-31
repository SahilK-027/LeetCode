/*
92 ms
71.3 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Reverse LL
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

//APPROACH :
/*
STEP 1: REVERSE LIST 1
STEP 2: REVERSE LIST 2
STEP 3: GENERATE ANSWER LIST BY INSERTING NODES TO START SO THAT NO NEED TO REVERSE ANS AGAIN
STEP 4: RETURN ANSWER LIST
*/
class Solution {
private:
    // Function to reverse a list
    ListNode* reverse(ListNode* list){
        if(list ->next == NULL){
            return list;    // No need to reverse list with single node
        }
        ListNode* curr = list;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void AddToHead(ListNode* &head, int data){
        ListNode* n1 = new ListNode(data);
        if(head == NULL){
            head = n1;
        }
        else{
            n1 -> next = head;
            head = n1;
        }
    }
    ListNode* add(ListNode* l1, ListNode* l2){
        int carry = 0;
        ListNode* ansList = NULL;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int data1 = 0;
            int data2 = 0;
            if(l1 != NULL){
                data1 = l1->val;
            }
            if(l2 != NULL){
                data2 = l2->val;
            }
            int sum = data1 + data2 + carry;
            int last_digit_in_sum = sum % 10;
            AddToHead(ansList , last_digit_in_sum);
            carry = sum / 10;
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        return ansList;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // STEP 1
        ListNode* r_l1 = reverse(l1);
        
        // STEP 2
        ListNode* r_l2 = reverse(l2);
        
        // STEP 3
        ListNode* ans = add( r_l1 ,r_l2);
        
        // STEP 4
        return ans;
        
    }
};