/*
6 ms
7.8 MB

TC : O(N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Recursive solution + DP
*/


class Solution {
private:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        // Array size is exceeded
        if(i > j){
            return 0;
        }

        // Both pointers are standing on a same element
        if(i == j){
            return arr[i];
        }

        // If already calculated return ans
        if(dp[i][j] != -1) return dp[i][j];

        // Calculate option 1 for player 1 : When p1 selects arr[i]
        // Calculate option 2 for player 1 : When p1 selects arr[j]
        int op1 = arr[i] + min(solve(arr, i+2, j, dp), solve(arr, i+1, j-1, dp));
        int op2 = arr[j] + min(solve(arr, i+1, j-1, dp), solve(arr, i, j-2, dp));

        // Store answer
        return dp[i][j] = max(op1, op2);
    }
public:
    bool PredictTheWinner(vector<int>& arr) {
        // Fast i/o
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        // Finding total score
        int total_score = 0 ;
        for(int i = 0 ; i < arr.size() ; i++){
            total_score += arr[i];
        }

        // Create dp
        vector<vector<int>>dp(arr.size(), vector<int>(arr.size(), -1));

        // Calculate score for p1 pass dp
        int p1_score = solve(arr,0, arr.size()-1, dp);
        int p2_score = total_score - p1_score;
        // Return
        return p1_score >= p2_score;
    }
};