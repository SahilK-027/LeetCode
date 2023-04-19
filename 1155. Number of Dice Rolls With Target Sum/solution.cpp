/*
Runtime : 42 ms
Memory : 8.4 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

#define M 1000000007
class Solution {
private:
    int solveTab(int n, int k, int target){
        vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= target; j++)
            {
                int ans = 0; 
                for(int x = 1 ; x <= k ; x++){
                    if(j - x >= 0){
                        ans = ans % M + dp[i-1][j-x] % M;
                    }
                }
                dp[i][j] =  ans % M;
            }
        }
        return dp[n][target];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        return solveTab(n, k, target);
    }
};