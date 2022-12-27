/*
392 ms
86.7 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Reciursive solution  + DP 
*/

class Solution {
private:
    int solve(int n, vector<int>& cost, vector<int>& dp){
        // Cannot reach
        if(n < 0 ){
            return 0;
        }
        // Reached out of array or on last index
        if(n == 0 || n == 1){
            return cost[n];
        }
        // If answer is already in DP
        if(dp[n] != -1) return dp[n];
        // Return min answer
        return dp[n] = cost[n] + min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
};