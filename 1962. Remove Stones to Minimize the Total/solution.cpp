/*
728 ms
105.2 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Heap
*/

/**
 * @brief 
We want to minimize the total so, each time we'll reduce the stone from the pile having maximum number of stones
Max heap is the data structure that gives us the max element from array in O(1) time
Array = [4,3,6,7]
MaxHeap =>
| 7 |
| 6 |
| 4 |
| 3 |
top = 7
Reduction= 7 / 2 = 4
Again push 4 to priority queue
and perform operations while k > 0
*/


class Solution {
public:
    int minStoneSum(vector<int>& arr, int k) {
        priority_queue<int> pq;
        for(auto i: arr){
            pq.push(i);
        }
        while(k--){
            int front = pq.top();
            pq.pop();
            float f = front * 1.0 / 2;
            int x = ceil(f);
            pq.push(x);
        }
        int sum = 0;
        while(!pq.empty()){
            int front = pq.top();
            pq.pop();
            sum+=front;
        }
        return sum;
    }
};