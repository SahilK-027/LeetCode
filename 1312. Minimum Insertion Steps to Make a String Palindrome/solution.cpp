/*
67 ms
28.3 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : SahilK-027
 * @brief : DP
*/

// Ans = length of the string - longest palindromic subsequence.

class Solution {
private:
    int solve(string& s, vector<vector<int>>&dp, int start, int end)
    {
        if (start == end) return 1;
        if (start > end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        
        if (s[start] == s[end]) return (2 + solve(s, dp, start + 1, end - 1)); //directly return         
        int leaveLeft = solve(s, dp, start + 1, end);
        int leaveRight = solve(s, dp, start, end - 1);
        return dp[start][end] = max(leaveLeft, leaveRight); //store the ans
    }
    int longestPalindromeSubseq(string& s) 
    {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int ans = solve(s, dp, 0, n - 1);
        return ans;
    }
public:
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};