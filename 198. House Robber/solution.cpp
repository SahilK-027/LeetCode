/*
0 ms
7.9 mb

TC: O(N)
SC: O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Recursion + Optimization (DP)
*/

class Solution {
private:
    int solve(vector<int>& arr, int s, int e, vector<int>& dp){
        // Base case
        if(s > e){
            return 0;
        }

        // DP step 3 : If answer is already calculated then directly return it
        if(dp[s] != -1){
            return dp[s];
        }

        // Rob current house so that you can rob next to next house
        int include = arr[s] + solve(arr, s+2, e, dp);

        // Leave current house so that you can rob next house
        int exclude = solve(arr, s+1, e, dp);

        // Return max of these two answers
        int ans =  max(include, exclude);
        
        // DP step 2 : Once answer calculated store it in DP
        dp[s] = ans;
        return ans;
    }
public:
    int rob(vector<int>& arr) {
        int s = 0;
        int e = arr.size()-1;
        // DP step 1 :  Create DP
        vector<int> dp(e+1, -1);
        return solve(arr, s, e, dp);
    }
};