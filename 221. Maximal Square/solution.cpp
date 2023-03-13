/*
95 ms
21.1 MB
*/

/**
 * TC: O(n)
 * SC: O(n*n)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    int solveMemoization(vector<vector<char>>& matrix, int i, int j, int &maxi, vector<vector<int>>& dp){
        // Base case
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        // Explore for all directions
        int right = solveMemoization(matrix, i, j+1, maxi, dp);
        int bottom = solveMemoization(matrix, i+1, j, maxi, dp);
        int diagonal = solveMemoization(matrix, i+1, j+1, maxi, dp);

        // If current elment is 1 then process otherwise you cannot form sqare so return 0
        if(matrix[i][j] == '1'){
            // 1 + because we will incluyde current block
            int ans = 1 + min(right, min(bottom, diagonal));
            maxi = max(maxi, ans);
            return dp[i][j] =  ans;
        }
        else{
            return dp[i][j] = 0;
        }
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        solveMemoization(matrix, 0, 0,maxi, dp);
        return maxi * maxi;
    }
};