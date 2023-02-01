/*
531 ms
178.7 MB
*/

/**
 * TC: O(1)
 * SC: O(N)
 */

/**
 * @author : SahilK-027
 * @brief :  Hashing + Doubly Linked List
*/

class LRUCache {
public:
    // Step 1: Create a doubly linked list to store the nodes with key value
    // The most recently used node will be at head and least recently used node will be at tail
    class ListNode{
        public: 
            int key;
            int val;
            ListNode* next;
            ListNode* prev;
            // Constructor to initialize the node
            ListNode(int key, int val){
                this->key = key;
                this->val = val;
            }
    };
    // Initial Configuration of linked list 
    // Insert The dummy nodes in list first
    ListNode* head = new ListNode(-1, -1);  
    ListNode* tail = new ListNode(-1, -1);  

    int cap;
    // The functions get and put must each run in O(1) average time complexity.
    // So we will use map map will store key and node's address in DLL.
    unordered_map<int, ListNode*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        // Join the doubly linked list
        head->prev = nullptr;
        head->next = tail;
        tail->next = nullptr;
        tail->prev = head;
    }
    
    // Insert node in linked list
    // We will always insert at the head so that the new node will be most recently used
    void insert(ListNode* node){
        ListNode* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    // Delete node in linked list
    // We will always delete from tail as the least recently node will be there at tail
    void deletenode(ListNode* node){
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    // findind value in map 
    // if present return value and update node as most recently used
    // else return -1
    int get(int key) {
        if(mp.find(key) != mp.end()){
            ListNode* resultNode = mp[key];
            int ans =  resultNode->val;
            mp.erase(key);
            // To update node
            // first delete it from list
            deletenode(resultNode);
            // reinsert node to linked list
            insert(resultNode);
            // Update it in map
            mp[key] = head->next;

            return ans;
        }
        else{
            return -1;
        }
    }

    void put(int key, int value) {
        // If key is already there in mp update value and add it as most recently used
        if(mp.find(key) != mp.end()){
            ListNode* existingNode = mp[key];
            mp.erase(key);
            deletenode(existingNode);
        }
        // If we reach capacity remove least recenly used (at tail)
        if(mp.size() == this->cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        // put new node
        insert(new ListNode(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */