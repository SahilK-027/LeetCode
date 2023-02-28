/*
63 ms
42.3 MB

TC: O(n)
SC: O(n)

@author: SahilK-027
@breif: Recursion + Memoization
*/
/**
 * @param {number[]} cost
 * @return {number}
 */

function solve(cost, k, dp){
    // Base case
    if( k == 0 ){
        return cost [0];
    }
    if( k == 1 ){
        return cost[1];
    }
    // If cached then return 
    if(dp[k] != -1){
        return dp[k];
    }
    // Otherwise store ans in dp and then return
    return dp[k] = Math.min(solve(cost, k - 1, dp), solve(cost, k - 2, dp)) + cost[k];
}
var minCostClimbingStairs = function(cost) {
    // Extracting size of input so to get number of stairs
    let n = cost.length;

    // Initializing DP of size n + 1 with -1
    let dp = new Array(n + 1);
    dp.fill(-1);

    // Getting ans as minimum of 1 step call and 2 step call
    let ans = Math.min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return ans;
};
