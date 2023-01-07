/*
219 ms
76.4 MB

TC : O(N log N)
SC : O(1)
*/

/**
 * @author : SahilK-027
 * @brief :  Sort + Greedy 
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // We want to pick maximum number of ice cream bars so we will pick icecream with least cost first and hence sort
        sort(costs.begin(), costs.end());
        int i = 0;
        int cnt = 0;
        // While we have coins
        while(coins > 0 && i < costs.size()){
            // Deduct coin to buy icecream
            coins -= costs[i];
            // If we have coins increase count of increase
            if(coins >= 0){
                cnt++;
            }
            i++;
        }
        // Return count
        return cnt;
    }
};