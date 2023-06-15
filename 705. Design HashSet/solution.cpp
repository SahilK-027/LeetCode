/*
117 ms
184.5 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Design
*/

class MyHashSet {
private:
    vector<int>arr = vector<int>(1000001);
public:    
    void add(int key) {
        this->arr[key] = 1;
    }
    
    void remove(int key) {
        if(this->arr[key] == 1){
            this->arr[key] = 0;
        }
    }
    
    bool contains(int key) {
        if(this->arr[key] == 1){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */