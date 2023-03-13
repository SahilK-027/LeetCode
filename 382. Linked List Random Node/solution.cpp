/*
26 ms
16.8 MB
*/

/**
 * TC: O(n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Array
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
public:
    vector<int> arr;
    Solution(ListNode* head) {
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int n = arr.size();
        int rand_idx = rand() % n;
        return arr[rand_idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */