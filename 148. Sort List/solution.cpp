/*
419 ms
50.9 mb

TC : O(N log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution
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
    ListNode* solve(ListNode* h1, ListNode* h2){
        ListNode* prev = h1;
        ListNode* curr = h1->next;
        ListNode* temp = h2;
        while(temp != NULL && curr != NULL)
        {
            if(temp->val >= prev->val && temp->val <= curr->val)
            {
                prev->next = temp;
                temp = temp->next;
                prev->next->next = curr;
                prev = prev->next;
            }
        else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
        
        if(curr == NULL && temp != NULL)
             prev->next = temp;
        return h1;
    }
    ListNode* merge(ListNode* head, ListNode* mid){
        ListNode* h1 = head;
        ListNode* h2 = mid;
        //check if either of list is empty 
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;
        ListNode* ans = NULL;
        if(h1->val <= h2->val)  //For case like[1,2,3,4][5,6,7,8] 
            ans = solve(h1,h2);
        if(h1->val > h2->val)  //For case like [5,6,7][1,2,3,4]
            ans = solve(h2,h1);
        return ans;
    }
    ListNode* mergeSort(ListNode* head)
    {
        // Base Case
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        //Finding mid and breaking list into two halves.
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow;
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        // Recursive Call
        left = mergeSort(left);
        right = mergeSort(right);
        
        //Processing
        ListNode* ans = merge(left,right);
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};