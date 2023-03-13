/*
3 ms
6.1 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Iterative
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        ans += numBottles;
        while(numBottles >= numExchange){
            numBottles -= numExchange;
            numBottles++;
            ans++;
        }
        return ans;
    }
};