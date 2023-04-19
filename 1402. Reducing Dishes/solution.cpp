/*
Runtime : 66 ms
Memory : 21 MB

TC : O( N * N)
SC : O( M * N)
*/

/**
 * @author : Sahilk-027
 * @brief : Dynamic Programming
*/

class Solution {
private:
    int solveMemoization(vector<int>& arr, int i, int time, vector<vector<int>>& dp){
        if( i >= arr.size()) return 0;
        // Step 3: Check if answer in already calculated or not
        if(dp[i][time] != -1) return dp[i][time];

        // Include case
        int include = time * arr[i] + solveMemoization(arr, i+1, time+1, dp);
        // Exclude case
        int exclude = 0 + solveMemoization(arr, i+1, time, dp);

        // Step 2: Store the answer indp
        return dp[i][time] =  max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int time = 1;
        // Step 1: Create dp and pass it to recursive function call
        vector<vector<int>> dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        return solveMemoization(arr, 0, time, dp);
    }
};