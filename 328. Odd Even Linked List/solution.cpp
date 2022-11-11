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
    //Fast and prev ptr approach
private: 
    void insertAtTail(ListNode* &newListHead,ListNode* &newListTail,int data){
        ListNode* n1 = new ListNode(data);
        if(newListHead == NULL){
            newListHead = n1;
            newListTail = n1;
            return;
        }
        else{
            newListTail->next = n1;
            newListTail = n1;
        }
    }
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            // 0 1 or 2 nodes
            return head;
        }
        ListNode* prev = head;
        ListNode* fast = head->next;
        ListNode* newListHead = NULL;
        ListNode* newListTail = newListHead ; 
        while(fast != NULL && fast->next != NULL){
            insertAtTail(newListHead,newListTail, fast->val);
            prev->next = fast->next;
            prev = fast->next;
            fast = fast->next->next;
        }
        if(fast != NULL){
            insertAtTail(newListHead,newListTail,fast->val);
            prev->next = NULL;
        }
        prev->next = newListHead;
        return head;
    }
};