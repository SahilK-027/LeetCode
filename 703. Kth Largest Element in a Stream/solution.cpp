/*
33 ms
19.6 MB

TC : O(NlogN)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap
*/

class KthLargest {
private:
    // We'll maintain min hip of size k
    // Say k = 3
    // Then our min heap will have only 3 elements among the total
    // And the min of this 3 numbers will be the kth Largest Element in a Stream
    void fastIO(){
        cin.tie(0);
        ios_base::sync_with_stdio(0);
    }
    priority_queue<int, vector<int>, greater<int>>pq;
    int k = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        fastIO();
        this->k = k;
        for(auto i: nums){
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > this->k){
            pq.pop();
        } 
        int ans = pq.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */