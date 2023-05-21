/*
5 ms
7.7 MB

TC : O(N log N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones){
            pq.push(i);
        }
        while(pq.size() > 1){
            int first = pq.top(); // y 
            pq.pop();
            int second = pq.top(); // x
            pq.pop();
            if(first != second){
                pq.push(first - second);
            }
        }
        return pq.size() == 1 ? pq.top(): 0;
    }
};