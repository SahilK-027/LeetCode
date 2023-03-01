/*
⚠️ This solution will give TLE as it need further optimization using memoization.
*/

/**
 * TC: O(k^n) k -> size of input array
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Brute Force Recursion
*/

class Solution {
private:
    int solve(vector<int>& coins, int amount){
        // Base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        // Processing
        int mini = INT_MAX;
        for(auto i: coins){
            int ans = solve(coins, amount - i);

            if(ans != INT_MAX){
                mini = min(mini, 1 + ans);
            }
        }
        return mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        int ans = solve(coins, amount);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};