/*
12 ms
10.5 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : List Traversal + Iteration
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

/*
Approach
Construct two lists one ontaining all the less elements and one containing all the greater or equal elements and then attach two lists
*/
class Solution {
private: 
    void insertAtTail(ListNode* &head, ListNode* &tail , int data){
        ListNode* n1 = new ListNode(data);
        if(head == NULL){
            head = n1;
            tail = n1;
        }
        else{
            tail->next = n1;
            tail = n1;
        }
    }
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* lessHead = NULL;
        ListNode* lessTail = NULL;
        ListNode* greaterEqualHead = NULL;
        ListNode* greaterEqualTail = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                insertAtTail(lessHead , lessTail , temp->val);
            }
            else{
                insertAtTail(greaterEqualHead , greaterEqualTail, temp->val);
            }
            temp = temp->next;
        }
        if(lessHead == NULL){
            return greaterEqualHead;
        }
        lessTail->next = greaterEqualHead;
        return lessHead;
    }
};
