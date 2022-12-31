/*
156 ms
47.3 MB

TC : O(log N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int>, greater<int>> pq;
        // Step 1: Build heap from first k elements
        for(int i = 0 ; i < k ; i++){
            pq.push(nums[i]);
        }

        // Step 2: For remaining n -k elements
        for(int i = k ; i < nums.size() ; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            } 
        }

        // Step 3: Your answer will be top of heap
        int ans = pq.top();
        return ans;
    }
};