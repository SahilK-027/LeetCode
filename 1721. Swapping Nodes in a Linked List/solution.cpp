/*
733 ms
188 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursion
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
    int len(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    void solve(ListNode* head, int k, ListNode** f, ListNode** b, int length, int& cnt){
        if(head == NULL) return;
        cnt++;
        if(cnt == k){
            *f = head;
        }
        solve(head->next, k, f, b, length, cnt);
        cnt--;
        if(cnt == (length - k)){
            *b = head;
        }
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* forward = NULL;
        ListNode* backward = NULL;
        int length = len(head);
        int cnt = 0;
        solve(head, k, &forward, &backward, length, cnt);
        swap(forward->val, backward->val);
        return head;
    }
};