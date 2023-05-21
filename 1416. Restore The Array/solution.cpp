/*
77 ms
20.7 MB

TC : O(N*N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : DP
*/

class Solution {
public:
    int MOD = 1000000007;
    int solve(string& s, int& k, vector<int>&dp, int index)
    {
        if (index == s.size()) return 1;
        
        if (dp[index] != -1) return dp[index];
        long long currNum = 0, ways = 0;
        for (int i = index; i < s.size(); i++)
        {
            int currDig = s[i] - '0';
            currNum = (currNum * 10) + currDig; 

            if (currNum < 1 || currNum > k) break;
            int nextWays = solve(s, k, dp, i + 1);
            ways = (ways +  nextWays) % MOD;
        }
        return dp[index] = ways; 
    }
    int numberOfArrays(string s, int k) 
    {
        vector<int>dp(s.size(), -1);
        int ans = solve(s, k, dp, 0);
        return ans;
    }
};