/*
47 ms
13.3 mb

TC: O(N)
SC: O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Recursion + Memoization (DP)
*/

class Solution {
private:
    int solve(string& s1, string& s2, int ans, vector<vector<int>>& dp, int i = 0, int j = 0){
    if(i == s1.length() || j == s2.length()){
        return ans;
    }

    // Step 3: Return answer if already calculated
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // Match case
    if(s1[i] == s2[j]){
        return dp[i][j] =  1 + solve(s1, s2,ans,dp,i + 1, j+1);
    }

    // Not match
    else{
        return dp[i][j] =  max(solve(s1, s2,ans,dp,i, j+1), solve(s1, s2,ans,dp, i + 1, j));
    }
}
public:
    int longestCommonSubsequence(string s1, string s2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s1.length();
        int m = s2.length();
        // Step 1: Init DP
        vector<vector<int>> dp(n,vector<int>(m, -1));
        return solve(s1, s2, 0, dp);
    }
};