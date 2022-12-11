/*
* 195 ms
* 30.9 mb
*/
/**
 * @author : Sahilk-027
 * @brief : Using next_free_space array
*/

class Allocator {
private:
    int capacity;
    // Original array
    int* arr;
    // This array will hold the number of next free spaces including current position
    int* next_free_space;
public:
    Allocator(int size) {
        // Fast i/0
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        // Initialization
        this->capacity = size;
        this->arr = new int[capacity];
        // Initializing the array with INT_MIN (Or any flag)
        for(int i = 0; i < capacity; i++){
            arr[i] = INT_MIN;
        }
        // For 0th index next free spaces will be 10 i.e. capacity - 0
        this->next_free_space = new int[capacity];
        for(int i = 0; i < capacity; i++){
            next_free_space[i] = capacity - i;
        }
    }
    
    int allocate(int size, int mID) {
        int curr_index = -1;
        // Traversing array for finding available space
        for(int i = 0 ; i < this->capacity ; i++){
            // If space available
            if(next_free_space[i] >= size){
                // For whichever i we get free space we'll start filling
                for(int j = 0 ; j < size ; j++){
                    arr[i+j] = mID;
                    // No space will left
                    next_free_space[i+j] = 0;
                }
                // We have to return first index from which we had start filling
                curr_index = i;
                break;
            }
        }
        return curr_index;
    }
    
    int free(int mID) {
        // We have to return count of deleted element
        int cnt = 0;
        for(int i = 0 ; i < this->capacity ; i++){
            if(arr[i] == mID){
                arr[i] = INT_MIN;
                cnt++;
            }
        }

        // Update next_free_space
        int freespace_cnt = 1;
        for(int i = this->capacity - 1 ; i>= 0; i--){
            // If array of i is INT_MIN means free space is available 
            if(arr[i] == INT_MIN){
                next_free_space[i] = freespace_cnt;
                freespace_cnt++;
            }
            // If array of i is not INT_MIN means free space should be reset to 1
            else{
                freespace_cnt = 1;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
