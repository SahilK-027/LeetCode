/*
0 ms
6.6 MB
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution + Memoization
*/

/*Finding Pattern
i/p             no. of ways             pattern
n = 0               0                  return 0 
n = 1               1                  return 1
n = 2               2                  return 2
n = 3               5         =>        2 * 2 + 1 => 2 * Ans(n = 2) + Ans(n-3)
n = 4               11        =>        2 * 5 + 1 => 2 * Ans(n = 3) + Ans(n-3)    
n = 5               24        =>        2 * 11 + 2 => 2 * Ans(n = 4) + Ans(n-3)    
*/

// Recursive Solution + DP
class Solution {
private:
    long long solve(int n, vector<long long>& dp){
        if(n <= 2){
            return n;
        }
        if(n == 3){
            return 5;
        }
        if(dp[n] != -1) return dp[n];
        long long ans =  (2 * solve(n-1, dp) + solve(n-3, dp)) % 1000000007;
        dp[n] = ans;
        return ans;
    }
public:
    int numTilings(int n) {
        vector<long long> dp(n+1, -1);
        return solve(n,dp) / 1ll;
    }
};