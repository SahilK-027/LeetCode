/*
87 ms
17.6 MB
*/

/**
 * TC: O(n)
 * SC: O(n)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic programming
*/

class Solution {
private:
    int solve(vector<int>& coins, int amount, vector<int>&dp){
        // Base case
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        // Step 3: DP analysis after base case
        if(dp[amount] != -1) return dp[amount];
        // Processing
        int mini = INT_MAX;
        for(auto i: coins){
            int ans = solve(coins, amount - i, dp);

            if(ans != INT_MAX){
                mini = min(mini, 1 + ans);
            }
        }
        // Step 2: store the answer in DP before returning
        return dp[amount] = mini;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        // Step 1: Create DP Array and pass it to the recursive function
        vector<int>dp(amount+1 , -1);
        int ans = solve(coins, amount, dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};