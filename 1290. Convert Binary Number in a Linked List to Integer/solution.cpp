/*
6 ms
8.4 MB

TC : O(N)
SC : O(N)
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
    //RECURSIVE APPROACH
private:
    int solve(ListNode* head, int &k){
        //Base case
        if(head == NULL){
            return k;
        }
        // we will first travel the whole list and calculate ans while returning
        // As binary degit is calculated from LSB TO MASB 
        int ans = solve(head->next,k);
        ans += head->val * pow(2,k);
        k++;
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        int k =0;
        return solve(head,k);
    }
};