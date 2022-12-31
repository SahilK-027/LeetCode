/*
253 ms
134.6 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Doubly ended queue
*/

/*
Approach using doubly ended queue to keep track of maximum element.
Why Deque ? 
-> As when we move forward in each window what we are doing is, we are adding one element at back (push_back) and removing one element from front (pop_front). The Deque enables both of these operations to be completed in O(1) time.

TC : O(N)
SC : O(N)
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        vector<int> ans;
        deque<int> dq; // Storing index of max elements
     
        // Traversing through input
        for(int  i= 0 ; i< nums.size(); i++)
        {
            // Remove the elements from deque which are out of current window so if you are at i th index then i - k th index will be out of window
            int out_of_bound = i - k;
            if(!dq.empty() && dq.front() == out_of_bound){
                dq.pop_front();
            }
            
            // pop all smaller values from deque
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            
            // Push the new element in deque at back
            dq.push_back(i);
            
            // when the first window will be complete then start storing the max
            if(i>= k -1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};