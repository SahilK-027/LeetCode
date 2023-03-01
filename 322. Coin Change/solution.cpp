/*
87 ms
17.6 MB
*/

/**
 * TC: O(amount * coins.size())
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
    // Using Tabulation 
    int solveTab(vector<int>& coins, int amount){
        vector<int>dp(amount+1 ,INT_MAX);
        dp[0] = 0;

        for(int i = 1 ; i <= amount; i++){
            // Utilize all coins for current amount
            for(auto c: coins){
                // Checking for valid index
                if(i - c >= 0 && dp[i - c] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        else{
            return dp[amount];
        }
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
