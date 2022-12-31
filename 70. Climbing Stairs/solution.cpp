/*
0 ms
6.2 mb

TC : O(N)
SC : O(N)
*/

/**
 * @author : Sahilk-027
 * @brief : Using next_free_space array + Inclusion exclusion logic + Recursion + DP 
*/

class Solution {
private:
    int solve(int n, vector<int>& dp, int stair = 0){
        // Base case if we reach nth stair then return 1..As there is 1 possible solution
        if(stair == n){
            return 1;
        }
        // If we reach stair above n then no answer exists so return 0
        if(stair > n){
            return 0;
        }

        if(dp[stair] != -1){
            return dp[stair];
        }
        // Ans for 1 stair climb
        int ans1 = solve(n, dp, stair+1);
        // Ans for 2 stair climb
        int ans2 = solve(n, dp, stair+2);
        
        // Final ans
        int final_ans = ans1 + ans2;
        dp[stair] = final_ans;
        return final_ans;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};