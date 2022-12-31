/*
4 ms
7.1 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Two stack = Queue
*/

class MyQueue {
private:
    stack<int> input;
    stack<int> output;
public:
    
    void push(int x) {
        this->input.push(x);
    }
    
    int pop() {
        if(this->output.empty())
        {
            while(!this->input.empty()){
                int element = this->input.top();
                this->output.push(element);
                this->input.pop();
            }
        }
        int ans = this->output.top();
        this->output.pop();
        return ans;
    }
    
    int peek() {
        if(this->output.empty())
        {
            while(!this->input.empty()){
                int element = this->input.top();
                this->output.push(element);
                this->input.pop();
            }
        }
        int ans = this->output.top();
        return ans;
    }
    
    bool empty() {
        if(this->input.empty() && this->output.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */