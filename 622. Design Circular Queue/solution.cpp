class MyCircularQueue {
private:
    int front;
    int rear;
    int *arr;
    int size;
public:
    MyCircularQueue(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        this->size = n;
        this->arr = new int[size];
        this->front = this->rear = -1;
    }
    
    bool enQueue(int value) {
        // Full queue
        if((front == 0 && rear == this->size-1) || (rear == (front-1))){
            //cout<<"Queue is full";
            return false;
        }
        
        // Empty queue
        else if(front == -1){
            front = 0;
            rear = 0;
        }
        
        // Rear end if full
        else if(rear == this->size-1 && front!= 0){
            rear = 0;
        }
        // Normal case
        else{
           rear++;
        }
        arr[rear] = value;
        return true;   
    }
    
    bool deQueue() {
        // Empty queue
        if(front == -1){
            return false;
        } 
        arr[front] = -1;
        if(front == rear)
        {
            // Only 1 elelement in queue
            front = rear = -1;
        }
        else if(front == this->size-1){
            // Front at last element
            front = 0;
        }
        else{
            // Normal case
            front++;
        }
        return true;

    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
         if(rear == -1){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || rear == (front - 1)){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */