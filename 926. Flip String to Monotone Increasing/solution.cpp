/*
319 ms
87.8 MB

*/

/**
 * @author : SahilK-027
 * @brief :  Recursion + Memoization
*/

class Solution
{
private:
    int solve(int i, string &s, int prev, vector<vector<int>> &dp)
    {
        // Base case
        if (i >= s.length())
            return 1;

        // If already calculated then return
        if (dp[i][prev] != -1)
            return dp[i][prev];

        // flip or not flip
        int flip = 0;
        int notFlip = 0;
        if (prev == 1)
        {
            if (s[i] == '1')
                flip = 0 + solve(i + 1, s, 1, dp);
            else
                flip = 1 + solve(i + 1, s, 1, dp);
            return dp[i][prev] = flip;
        }
        // If current is 1 we won't flip it
        if (s[i] == '1')
        {
            flip = 0 + solve(i + 1, s, 1, dp);
            notFlip = 1 + solve(i + 1, s, 0, dp);
        }
        // If curret is 0 we will try to flip it
        if (s[i] == '0')
        {
            flip = 1 + solve(i + 1, s, 1, dp);
            notFlip = solve(i + 1, s, 0, dp);
        }
        // Store answer
        int ans = min(flip, notFlip);
        dp[i][prev] = ans;
        return ans;
    }

public:
    int minFlipsMonoIncr(string s)
    {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        // Start index
        int i = 0;
        // Dp init
        vector<vector<int>> dp(s.length() + 1, vector<int>(2, -1));
        return solve(i, s, 0, dp) - 1;
    }
};