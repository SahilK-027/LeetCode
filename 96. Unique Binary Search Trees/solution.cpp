/*
0 ms
6.1 MB
*/

/**
 * @author : SahilK-027
 * @brief : Recursion + DP
*/

// Catlen number logic
class Solution {
private:
    int solve(int n, vector<int>& dp){
        // Base case
        if (n <= 1) return 1;
        if(dp[n] != -1){
            return dp[n];
        }
        unsigned long int res = 0;
        for (int i = 0; i < n; i++){
            res += solve(i, dp) * solve(n - i - 1, dp);
        } 
        dp[n] = res;
        return res / 1ll;
    }
public:
    int numTrees(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};