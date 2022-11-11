// Data Structure that we will be inserting in min heap
class Node{
    public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Custome comparator for min heap
class Comparator{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& arr) {
        // Step 1: Initialize important data and datastructures
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<Node*, vector<Node*>, Comparator> minHeap;
        int k = arr.size();

        // Step 2: Insert the first element of each list in min heap
        for(int i = 0 ; i < k ; i++){
            int element = arr[i][0];
            // Creating node of first element of each row and pushing in minHeap
            Node* temp = new Node(element, i, 0);
            minHeap.push(temp);
            // Keeping track of max and min
            maxi = max(element, maxi);
            mini = min(element,mini);
        }

        // Step 3: Defining initial range
        int start = mini;
        int end = maxi;

        // Step 4: Processing
        while(!minHeap.empty()){
            // Extract and pop top of min heap
            Node* top = minHeap.top();
            minHeap.pop();
            // Update mini
            mini = top->data;
            // Update range
            int curr_range_diff = maxi - mini;
            int initial_range_diff = end - start;
            if(curr_range_diff < initial_range_diff){
                start = mini;
                end = maxi;
            }
            // Checking if next element of list exists
            int curr_row_idx = top->row;
            int curr_col_idx = top->col;
            int next_col_idx = curr_col_idx+1;
            // If next column index is within the range of current row.size() then we can can say its valid
            if(next_col_idx < arr[curr_row_idx].size()){
                maxi = max(maxi, arr[curr_row_idx][next_col_idx]);
                Node* temp = new Node(arr[curr_row_idx][next_col_idx], curr_row_idx, next_col_idx);
                minHeap.push(temp);
            }
            else{
                // List is exhausted Stop
                break;
            }
        }
        // Step 5: Answer
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};