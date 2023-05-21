/*
408 ms
121.4 MB

TC : O(N * N)
SC : O(N)
*/

/**
 * @author : SahilK-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    long long solve(vector<vector<int>>& questions, int i, vector<long long>& dp){
        if(i >= questions.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        // Include call
        long long include = questions[i][0] + solve(questions, (i + 1) + questions[i][1], dp);
        // Exclude call
        long long exclude = 0 + solve(questions, i + 1, dp);

        return dp[i] = max(include, exclude);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size()+1, -1);
        return solve(questions, 0, dp);
    }
};