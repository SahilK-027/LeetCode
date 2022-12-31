/*
5 ms
10.8 MB

TC : O(N)
SC : O(1)
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
    void deleteFirstNode(ListNode *&start)
    {
        if (start == NULL)
        {
        return;
        }
        ListNode *temp;
        temp = start;
        start = temp->next;
        delete temp;
    }
    void deleteLastnode(ListNode* &start)
    {
        if (start == NULL){
            return;
        }
        ListNode *temp1;
        ListNode *temp2;
        temp1 = start;
        temp2 = NULL;
        while (temp1->next != NULL){
            temp2 = temp1;
            temp1 = temp1->next;
        }
        if (temp2){
            temp2->next = NULL;
            delete temp1;
            return;
        }
        start = NULL;
        delete temp1;
    }
    ListNode* delete_Kth_Node(ListNode*& head,int n){
        ListNode* temp= head;
        int length = 1;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        int k = length - n;
        int x =1;
        ListNode* t1= head;
        ListNode* t2= NULL;
        while(x!=k){
            t2 =t1;
            t1 =t1->next;
            x++;
        }
        if(t2){
            t2->next = t1->next;
            delete t1;
        }
        else{
            deleteFirstNode(head);
        }
        return head;
    }
    
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==1){
            deleteLastnode(head);
            return head;
        }  
        return delete_Kth_Node(head,n);
    }
};
