/*
20 ms
14.9 MB

TC : O(N)
SC : O(1) // The speciality of this algo is that it doesn't need extra space
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
    //Approach in constant space o(1)
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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        ListNode* h1 = list1;
        ListNode* h2 = list2;
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
};