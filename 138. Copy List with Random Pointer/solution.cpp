/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
// Approach 1: 
    /*
    1. Copy list using next pointers
    2. create Hash map
    3. Copy random pointers by using Hash Map
    */
// TC: O(N)
// SC: O(N)
    
private: 
    void insertAtTail(Node* &head,Node* &tail,int data){
        Node* n1 = new Node(data);
        if(head == NULL){
            head = n1;
            tail = n1;
            return;
        }
        tail -> next = n1;
        tail = n1;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* original = head;
        Node* copyHead = NULL;
        Node* copyTail = NULL;
        // 1. Copy list using next pointers
        while(original != NULL){
            insertAtTail(copyHead,copyTail,original->val);
            original = original->next;
        }
        // 2. create Hash map
        unordered_map<Node*, Node*> map;
        original = head;
        Node* temp = copyHead;
        while(original != NULL){
            map[original]= temp;
            original = original->next;
            temp = temp->next;
        }
        // 3. Copy random pointers by using Hash Map
        original = head;
        temp = copyHead;
        while(original != NULL){
            temp->random = map[original->random];
            original = original->next;
            temp = temp->next;
        }
        return copyHead;
    }
};