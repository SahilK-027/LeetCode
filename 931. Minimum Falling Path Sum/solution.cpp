/*
38 ms
10.4 mb
*/

/**
 * @author : Sahilk-027
 * @brief : Optimization using DP
*/


class Solution {
private:
    int solve(vector<vector<int>>& matrix, int n, int row, int col, vector<vector<int>>& dp){
        // Row index out of bound
        if(row >= n){
            return 0;
        }

        // Col index out of bound means we cannot expand the path further, as path is not possible return INT_MAX
        if(col < 0 || col >= n){
            return INT_MAX;
        }

        // Step 3: Check if answer is already calculated or not
        if(dp[row][col] != INT_MIN){
            return dp[row][col];
        }

        // Down
        int path1 = solve(matrix, n, row+1, col, dp);
        // Diagonal Right
        int path2 = solve(matrix, n, row+1, col+1, dp);
        // Diagonal Left
        int path3 = solve(matrix, n, row+1, col-1, dp);
        int ans = matrix[row][col] + min(path1, min(path2, path3));

        // Step 2: Store ans in DP
        dp[row][col] = ans;
        return ans;
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minPathSum = INT_MAX;

        // Step 1: Creatimng DP and passing to function
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));

        // First we will send recursive calls for first element of each column
        for(int col = 0 ; col < n ; col++){
            minPathSum = min(minPathSum, solve(matrix, n,0, col, dp));
        }
        return minPathSum;
    }
};