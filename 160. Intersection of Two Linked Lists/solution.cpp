/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    //Hash map approach
    /*
    1. Insert nodes of both linked lists in two separating maps
    2. While inserting in map2 check if node is already in map1 or not
       , lly while inserting in map1 check if node is already in map2 or not
       if found in any of two return that node
    3. Otherwise return NULL
    */
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        unordered_map<ListNode*, int> map1;
        unordered_map<ListNode*, int> map2;
        
        ListNode * temp1 = headA;
        ListNode * temp2 = headB;
        while(temp1 != NULL && temp2 != NULL){
            //Not foun in map then insert first
            if(map1.find(temp1) == map1.end()){
                map1.emplace(temp1 ,temp1->val);
            }
            if(map2.find(temp2) == map2.end()){
                map2.emplace(temp2 ,temp2->val); 
            }
            if(map1.find(temp2) != map1.end() ){
                // temp2 found in map1 
                return temp2;
            }
            if(map2.find(temp1) != map2.end()){
                //temp1 found in map2
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != NULL){
            if(map2.find(temp1) != map2.end()){
                // temp1 is found in map2
                return temp1;
            }
            else{
                map1.emplace(temp1 ,temp1->val);
            }
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            if(map1.find(temp2) != map2.end()){
                // temp1 is found in map2
                return temp2;
            }
            else{
                map2.emplace(temp2 ,temp2->val);
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};