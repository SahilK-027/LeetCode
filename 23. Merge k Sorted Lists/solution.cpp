/*
Runtime: 163 ms
Memory Usage: 13.1 MB
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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        //check if either of list is empty 
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;
        ListNode* ans = NULL;
        if(h1->val <= h2->val) 
             ans = solve(h1,h2);
        if(h1->val > h2->val)
             ans = solve(h2,h1);
        return ans;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        if(lists.size()==0){
            return  NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        ListNode* list1 = lists[0];
        ListNode* list2 = lists[1];
        ListNode* ans = mergeTwoLists(list1,list2);
        int n = lists.size();
        for(int i =2 ; i < n ;i++){
            ans = mergeTwoLists(ans,lists[i]);
        }
        return ans;
    }
};
