/*
Runtime: 9 ms
Memory Usage: 15.1 MB
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
    void insert(ListNode *&start, int data)
    {
        ListNode *n1 = new ListNode;
        n1->val = data;
        n1->next = NULL;
        if (start == NULL){
            start = n1;
        }    
        else
        {
            ListNode *temp;
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n1;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(list1 == NULL)
			return list2;
		if(list2 == NULL)
			return list1;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *result = NULL;
        while(temp1 !=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                insert(result,temp1->val);
                temp1 = temp1->next;
            }
            else{
                insert(result,temp2->val);
                temp2 = temp2->next;
            }
        }
        if(temp1 !=NULL){
            while(temp1 !=NULL){
                insert(result,temp1->val);
                temp1 = temp1->next;
            }
        }
        if(temp2 !=NULL){
            while(temp2 !=NULL){
                insert(result,temp2->val);
                temp2 = temp2->next;
            }
        }
        return result;
    }
};
