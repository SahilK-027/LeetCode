/*
4 ms
9.2 MB
*/
/**
 * TC: O(N log N)
 * SC: O(N)
*/
/**
 * @author : SahilK-027
 * @brief : Heap
 */

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        int n = gifts.size();
        for(int i = 0 ; i < n ; i++){
            pq.push(gifts[i]);
        }
        while(k--){
            int top = pq.top();
            pq.pop();
            int rem = floor(sqrt(top));
            pq.push(rem);
        }
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};