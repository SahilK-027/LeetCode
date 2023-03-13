/*
185 ms
9.6 MB
*/

/**
 * TC: O(n)
 * SC: O(1)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic programming
*/

class Solution {
private: 
    int solveMemoization(int n, vector<int>& dp){
        // Base case
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];

        // Initial answer
        int ans = INT_MAX;
        for(int i = 1; i * i <= n; i++){
            // Answer will be minimum of ans, subproblems solution
            ans = min(ans, 1 + solveMemoization(n - i * i, dp));
        }

        return dp[n] =  ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solveMemoization(n, dp);
    }
};