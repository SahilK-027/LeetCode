/*
Runtime : 10 ms
Memory : 10.1 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Recursion + Memoization
*/


class Solution {
private:
    int solve(vector<vector<int>>& grid, int m, int n,vector<vector<int>> &dp){
        // Base case
        if( m == 0 and  n == 0 ) return grid[0][0];
        if( m < 0 || n < 0) return 1000;

        if(dp[m][n] != -1) return dp[m][n];
        // Recursive call
        int up = grid[m][n] + solve(grid, m-1, n, dp);
        int left = grid[m][n] + solve(grid, m, n-1, dp);

        // Processing
        return dp[m][n] =  min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(grid,m , n,dp);
    }
};