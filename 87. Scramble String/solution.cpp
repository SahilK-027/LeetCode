/*
Runtime : 45 ms
Memory : 10.4 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Tabulation
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (!is_permutation(s1.begin(), s1.end(), s2.begin())) {
            return false;
        }
        
        int n = s1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n-length; i++) {
                for (int j = 0; j <= n-length; j++) {
                    for (int k = 1; k < length; k++) {
                        if ((dp[i][j][k] && dp[i+k][j+k][length-k]) || (dp[i][j+length-k][k] && dp[i+k][j][length-k])) {
                            dp[i][j][length] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n];
    }
};