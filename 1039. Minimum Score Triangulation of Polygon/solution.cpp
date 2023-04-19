/*
Runtime : 16 ms
Memory : 8.4 MB

TC : O(N * N)
SC : O(N * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    int solveMemoization(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        // Base case
        if(i + 1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        // Select k
        int ans = INT_MAX;
        for(int k = i + 1; k <= j -1 ; k++){
            int curr_ans = values[i] * values[j] *  values[k] + 
            solveMemoization(values, i, k, dp) + 
            solveMemoization(values, k, j, dp);

            ans = min(ans, curr_ans);
        }

        // Return ans
        return dp[i][j] =  ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>>dp(values.size(), vector<int>(values.size(), -1));
        return solveMemoization(values, 0, values.size()-1, dp);
    }
};