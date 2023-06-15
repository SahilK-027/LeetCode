/*
2 ms
8 MB

TC : O(N * M)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic programming
*/


class Solution {
private:
    int solveRec(int srcX, int srcY, vector<vector<int>>& grid){
        if(srcX == 0 && srcY ==0) return 1;
        if(srcX < 0 || srcY < 0 || grid[srcX][srcY] == 1) return 0;

        int leftCall = solveRec(srcX, srcY-1, grid);
        int upCall = solveRec(srcX-1, srcY, grid);

        return leftCall + upCall;
    }

    int solveMem(int srcX, int srcY, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(srcX == 0 && srcY ==0) return 1;
        if(srcX < 0 || srcY < 0 || grid[srcX][srcY] == 1) return 0;
        if(dp[srcX][srcY] != -1) return dp[srcX][srcY];
        
        int leftCall = solveMem(srcX, srcY-1, grid, dp);
        int upCall = solveMem(srcX-1, srcY, grid, dp);

        return dp[srcX][srcY] =  leftCall + upCall;
    }

    int solveTab(int m, int n, vector<vector<int>>& grid){
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(i == 0 && j == 0) continue;

                int leftCall = 0, upCall = 0;
                if(j > 0 && grid[i][j-1] == 0) leftCall =  dp[i][j-1];
                if(i > 0 && grid[i-1][j] == 0) upCall =  dp[i-1][j];
                dp[i][j] =  leftCall + upCall;
            }
        }
        return dp[m-1][n-1];       
    }

    int SO(int m, int n, vector<vector<int>>& grid){
        vector<int>prev(n, 0);
        prev[0] = 1;

        for(int i = 0 ; i < m ; i++){
            vector<int>curr(n, 0);
            for(int j = 0 ; j < n; j++){
                if(i == 0 && j == 0){
                    curr[0] = 1;
                    continue;
                } 
                int leftCall = 0, upCall = 0;
                if(j > 0 && grid[i][j-1] == 0) leftCall =  curr[j-1];
                if(i > 0 && grid[i-1][j] == 0) upCall =  prev[j];
                curr[j] =  leftCall + upCall;
            }
            prev = curr;
        }
        return prev[n-1];       
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;
        vector<vector<int>>dp(m, vector<int>(n, -1));

        return SO(m,n, grid);
        return solveTab(m, n, grid);
        return solveMem(m-1, n-1, grid, dp);
        return solveRec(m-1, n-1, grid);
    }
};