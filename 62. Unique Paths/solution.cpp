/*
0 ms
6.5 MB

TC : O(N * M)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic programming
*/


class Solution {
private:
    int solveRec(int srcX, int srcY){
        if(srcX < 0 || srcY < 0) return 0;
        if(srcX == 0 && srcY == 0) return 1;

        int leftCall = solveRec(srcX, srcY-1);
        int upCall = solveRec(srcX-1, srcY);

        return leftCall + upCall;
    }
    int solveMem(int srcX, int srcY, vector<vector<int>>&dp){
        if(srcX < 0 || srcY < 0) return 0;
        if(srcX == 0 && srcY == 0) return 1;

        if(dp[srcX][srcY] != -1) return dp[srcX][srcY]; 

        int leftCall = solveMem(srcX, srcY-1, dp);
        int upCall = solveMem(srcX-1, srcY, dp);

        return dp[srcX][srcY] = leftCall + upCall;
    }
    int solveTab(int m, int n){
        vector<vector<int>>dp(m, vector<int>(n,0));
        dp[0][0] = 1;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int leftCall = 0;
                int upCall = 0;
                if(j > 0) leftCall = dp[i][j-1];
                if(i > 0) upCall = dp[i-1][j];
                dp[i][j] = leftCall + upCall;
            }
        }
        return dp[m-1][n-1];
    }
    int SO(int m, int n){
        vector<int>prev(n,0);
        for(int i = 0 ; i < m ; i++){
            vector<int>curr(n,0);
            for(int j = 0 ; j < n; j++){
                if(i == 0 && j == 0){
                    prev[0] = 1;
                    curr[0] = 1;
                    continue;
                }
                int leftCall = 0;
                int upCall = 0;
                if(j > 0) leftCall = curr[j-1];
                if(i > 0) upCall = prev[j];
                curr[j] = leftCall + upCall;
            }
            prev = curr;
        }
        return prev[n-1];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return SO(m, n);
        return solveTab(m, n);
        return solveMem(m-1, n-1, dp);
        return solveRec(m-1, n-1);
    }
};